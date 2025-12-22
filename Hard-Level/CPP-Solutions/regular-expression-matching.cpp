/*
 * O(N*M)
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int textLength = s.size();
        int patternLength = p.size();

        // dp[ti][pi] = true if text[0..ti) matches pattern[0..pi)
        vector<vector<bool>> match(textLength + 1, vector<bool>(patternLength + 1, false));
        match[0][0] = true; // empty string matches empty pattern

        // Initialize patterns that can match an empty string (like a*, a*b*, a*b*c*)
        for (int patternIndex = 2; patternIndex <= patternLength; patternIndex++) {
            if (p[patternIndex - 1] == '*') {
                match[0][patternIndex] = match[0][patternIndex - 2];
            }
        }

        for (int textIndex = 1; textIndex <= textLength; textIndex++) {
            for (int patternIndex = 1; patternIndex <= patternLength; patternIndex++) {
                char currentPatternChar = p[patternIndex - 1];

                if (currentPatternChar == '.' || currentPatternChar == s[textIndex - 1]) {
                    // Single character match
                    match[textIndex][patternIndex] = match[textIndex - 1][patternIndex - 1];
                }
                else if (currentPatternChar == '*') {
                    // Zero occurrences of preceding char
                    match[textIndex][patternIndex] = match[textIndex][patternIndex - 2];

                    // One or more occurrences, if preceding matches
                    char precedingPatternChar = p[patternIndex - 2];
                    if (precedingPatternChar == '.' || precedingPatternChar == s[textIndex - 1]) {
                        match[textIndex][patternIndex] = match[textIndex][patternIndex] || match[textIndex - 1][patternIndex];
                    }
                }
            }
        }

        return match[textLength][patternLength];
    }
};
