// O(N)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dictionary;
        dictionary['I'] = 1;
        dictionary['V'] = 5;
        dictionary['X'] = 10;
        dictionary['L'] = 50;
        dictionary['C'] = 100;
        dictionary['D'] = 500;
        dictionary['M'] = 1000;

        int total = 0;
        int length = s.length();

        for(int i = 0;  i < length; i++)
        {
            if(dictionary[s[i]] < dictionary[s[length - 1 > i ? i + 1 : i]])
            {
                total -= dictionary[s[i]];
            } else {
                total += dictionary[s[i]];
            }
        }

        return total;
    }
};
