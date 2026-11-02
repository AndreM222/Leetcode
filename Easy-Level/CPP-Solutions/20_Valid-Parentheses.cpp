// --------------------------------------------[ Using Hashmap for Abstraction and Loop ]--------------------------------------------
// O(n)
class Solution {
private:
    unordered_map<char, char> partners;
public:
    bool isValid(string s) {
        partners[']'] = '[';
        partners[')'] = '(';
        partners['}'] = '{';

        vector<char> beginners;

        for(int i = 0; i < s.length(); i++) {
            if(partners.find(s[i]) == partners.end()) {
                beginners.push_back(s[i]);
                continue;
            }

            if(beginners.size() > 0 && beginners.back() == partners[s[i]]) {
                beginners.pop_back();
                continue;
            }

            return false;
        }

        if(beginners.size() > 0) return false;

        return true;
    }
};
