import json
import os
import subprocess
import sys


def get_language(folder_name, filename):
    """Get the language from the solution folder, with extension as fallback."""
    folder = folder_name.removesuffix("-Solutions")

    folder_languages = {
        "CPP": "C++",
        "C++": "C++",
        "PY": "Python",
        "PYTHON": "Python",
        "JS": "JavaScript",
        "JAVASCRIPT": "JavaScript",
        "JAVA": "Java",
    }

    if folder.upper() in folder_languages:
        return folder_languages[folder.upper()]

    extension = os.path.splitext(filename)[1].lower()
    extension_languages = {
        ".cpp": "C++",
        ".cc": "C++",
        ".cxx": "C++",
        ".py": "Python",
        ".js": "JavaScript",
        ".java": "Java",
    }

    return extension_languages.get(extension, extension or "Unknown")


def run_prettier(path):
    try:
        result = subprocess.run(
            ["npx", "prettier", "--write", path],
            check=True,
            capture_output=True,
            text=True
        )
        print(f"Formatted {path} successfully.")
        if result.stdout:
            print(result.stdout)
    except subprocess.CalledProcessError as e:
        print(f"Error formatting {path}:", file=sys.stderr)
        print(e.stderr, file=sys.stderr)


def dict_parser(path, ignored_names):
    name = os.path.basename(os.path.normpath(path))

    if name in ignored_names:
        return None

    if not os.path.isdir(path):
        return {
            "name": name,
            "src": "./" + os.path.relpath(path, ".").replace(os.sep, "/"),
            "language": None,
        }

    children = []
    for entry in sorted(os.listdir(path)):
        child_path = os.path.join(path, entry)
        result = dict_parser(child_path, ignored_names)

        if result is not None:
            children.append(result)

    if name.endswith("-Solutions"):
        language = name.removesuffix("-Solutions")
        for child in children:
            if isinstance(child, dict) and "src" in child:
                child["language"] = get_language(name, child["name"])
        return children

    if name.endswith("-Level"):
        difficulty = name.removesuffix("-Level")
        files = []

        def collect_files(nodes):
            for node in nodes:
                if isinstance(node, list):
                    collect_files(node)
                elif isinstance(node, dict) and "src" in node:
                    files.append(node)

        collect_files(children)

        problems = {}
        for solution in files:
            stem = os.path.splitext(solution["name"])[0]

            number, separator, slug = stem.partition("_")
            if not separator or not number.isdigit() or not slug:
                print(
                    f"Skipping filename without number_title format: {solution['src']}")
                continue

            problem_number = int(number)
            problem_name = slug.replace("-", " ")

            if problem_number not in problems:
                problems[problem_number] = {
                    "number": problem_number,
                    "name": problem_name,
                    "solutions": [],
                }

            problems[problem_number]["solutions"].append({
                "src": solution["src"],
                "language": solution["language"],
            })

        return {
            difficulty: [
                problems[number]
                for number in sorted(problems)
            ]
        }

    result = {}
    for child in children:
        if isinstance(child, dict):
            result.update(child)

    return result


def escape_cell(value):
    """Escape text for a Markdown table cell."""
    return str(value).replace("|", r"\|").replace("\n", " ")


def render_markdown(data):
    lines = []

    for difficulty in ("Hard", "Medium", "Easy"):
        problems = data.get(difficulty, [])

        lines.extend([
            f"## {difficulty}",
            "",
            "| # | Title | Solutions | Difficulty |",
            "| --- | --- | --- | --- |",
        ])

        for problem in problems:
            solution_links = []

            for solution in problem["solutions"]:
                src = solution["src"]
                language = solution["language"]
                solution_links.append(f"[{language}]({src})")

            lines.append(
                f"| {problem['number']} "
                f"| {escape_cell(problem['name'])} "
                f"| {', '.join(solution_links)} "
                f"| {difficulty} |"
            )

        lines.append("")

    return "\n".join(lines).rstrip()


def update_readme(readme_path, generated_markdown):
    start_marker = "<!-- solutions:start -->"
    end_marker = "<!-- solutions:end -->"

    with open(readme_path, "r", encoding="utf-8") as file:
        readme = file.read()

    if start_marker not in readme or end_marker not in readme:
        raise ValueError(
            f"Add {start_marker} and {end_marker} around the generated "
            "solution sections in README.md."
        )

    before, remainder = readme.split(start_marker, 1)
    _, after = remainder.split(end_marker, 1)

    updated = (
        before
        + start_marker
        + "\n\n"
        + generated_markdown
        + "\n\n"
        + end_marker
        + after
    )

    with open(readme_path, "w", encoding="utf-8") as file:
        file.write(updated)


if __name__ == "__main__":
    with open("./generator/mdignore.json", "r", encoding="utf-8") as file:
        ignored_names = set(json.load(file))

    result = dict_parser("./", ignored_names)

    print(json.dumps(result, indent=2, ensure_ascii=False))

    markdown = render_markdown(result)
    update_readme("./README.md", markdown)

    print("README.md updated.")

    run_prettier("./README.md")
