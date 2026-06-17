// --------------------------------------------[ Recursion ]--------------------------------------------
// O(2^n)
class Solution {
private:
    void groupGenerator(int total, int open, int close, string text, vector<string>& groups) {
        if(text.length() == total * 2) {
            groups.push_back(text);
            return;
        }

        if(open < total) {
            text.push_back('(');
            groupGenerator(total, open + 1, close, text, groups);
            text.pop_back();
        }

        if(close < open) {
            text.push_back(')');
            groupGenerator(total, open, close + 1, text, groups);
            text.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> groups;
        groupGenerator(n, 0, 0, "", groups);

        return groups;
    }
};
