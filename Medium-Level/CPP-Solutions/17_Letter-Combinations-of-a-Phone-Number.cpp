// --------------------------------------------[ Using Recursion and Loops ]--------------------------------------------
// O(2^n)
class Solution {
private:
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void groupUp(string digits, string group, int index, int length, vector<string>& groups) {
        if(index >= length) {
            groups.push_back(group);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for(int i = 0; i < letters.length(); i++) {
            string newGroup = group + letters[i];
            groupUp(digits, newGroup, index + 1, length, groups);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> groups;
        int length = digits.length();

        groupUp(digits, "", 0, length, groups);

        return groups;
    }
};
