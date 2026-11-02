// O(N)
class Solution {
public:
    int myAtoi(string s) {
        string number = "";
        bool beginnerTrail = true;
        char sign;

        // Parse through string for number conversion
        for(char curr : s)
        {
            // Check if initial is whitespace
            if(curr != ' ') beginnerTrail = false;

            // If its not numbers then check if should ignore
            if(curr < 48 || curr > 57)
            {
                // Stop if its not whitespace and number not parsed
                if(!number.empty()) break;

                // Only take in ignore if its not a signedness or whitespace
                if(curr != ' ' && curr != '+' && curr != '-') break;

                // Only stop if whitespace is not from start
                if(curr == ' ' && !beginnerTrail) break;

                // If its a minus then turn to negative
                if(number.empty() && (curr == '-' || curr == '+'))
                {
                    if(sign) break;

                    // Set sign
                    sign = curr;
                };

                // Ignore current character
                continue;
            }

            // If number then add
            number += curr;
        }

        // If no value then set to 0
        number = number.empty() ? "0" : number;
        if(sign == '-') number = sign + number;

        cout << "Test: " << number << endl;

        try
        {
            // If its within 32 bit then return
            return stoi(number);
        } catch (const std::out_of_range& e)
        { // Else catch exception and return max 32 possible value

            // Return negative max 32 bit
            if(number[0] == '-') return - pow(2, 31);

            // Return positive maximum 32 bit
            return pow(2, 31) - 1;
        }
    }
};
