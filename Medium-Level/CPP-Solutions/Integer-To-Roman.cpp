// O((log n)²)
class Solution {

private:
    unordered_map<int, char> dictionary;

    void separator(int num, vector<int>& groups)
    {
        string parser =  std::to_string(num);
        int length = parser.length() - 1;

        for(char curr : parser)
        {
            if(curr != '0')
            {
                int number = stoi(curr + string(length, '0'));
                groups.push_back(number);
            }

            length--;
        }
    }

    int setupDivider(int curr, int zeroes)
    {
        int divider = pow(10, zeroes);
        int range = curr / divider;
        divider = range > 8 ? divider * 10 : range > 3 ? divider * 5 : divider;

        return divider;
    }

    string romanConversion(vector<int> groups)
    {
        string roman = "";
        for(int curr : groups)
        {
            int zeroes = floor(log10(curr));
            int divider = setupDivider(curr, zeroes);

            while(curr > 0)
            {
                roman += dictionary[divider];
                curr -= divider;
                divider = setupDivider(curr, zeroes);
            }

            while(curr < 0)
            {
                char tmp = roman[roman.length() - 1];
                roman[roman.length() - 1] = dictionary[divider];
                roman += tmp;
                curr += divider;
                divider = setupDivider(curr, zeroes);
            }

        }

        return roman;
    }
public:
    string intToRoman(int num) {
        vector<int> groups;

        // Dictionary list set
        dictionary[1] = 'I';
        dictionary[5] = 'V';
        dictionary[10] = 'X';
        dictionary[50] = 'L';
        dictionary[100] = 'C';
        dictionary[500] = 'D';
        dictionary[1000] = 'M';

        separator(num, groups);
        return romanConversion(groups);
    }
};
