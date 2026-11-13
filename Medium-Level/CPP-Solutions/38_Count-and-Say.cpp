// --------------------------------------------[ Loop and Recursion ]--------------------------------------------
// O(N)
class Solution {
public:
    string countAndSay(int n) {
        string value = n > 0 ? "1" : "";
        char index;
        int counter;
        string newValue;
        for (int i = 1; i < n; i++) {
            counter = 0;
            newValue = "";
            index = value[0];

            for (int j = 0; j < value.length(); j++) {
                if (index != value[j]) {
                    newValue += to_string(counter);
                    newValue += index;
                    index = value[j];
                    counter = 0;
                }

                counter++;
            }

            if (counter > 0) {
                newValue += to_string(counter);
                newValue += index;
            }

            value = newValue;
        }

        return value;
    }
};
