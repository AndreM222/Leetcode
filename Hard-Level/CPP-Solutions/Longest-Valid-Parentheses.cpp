class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> list;
        list.push(-1);
        int maxLen = 0, length = s.length();

        for (int i = 0; i < length; i++) {
            if (s[i] == '(') {
                list.push(i);
            } else {
                list.pop();

                if (list.empty()) {
                    list.push(i);
                } else {
                    maxLen = max(maxLen, i - list.top());
                }
            }
        }

        return maxLen;
    }
};
