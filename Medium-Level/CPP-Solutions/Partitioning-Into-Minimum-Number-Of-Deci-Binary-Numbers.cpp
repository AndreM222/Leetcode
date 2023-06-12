class Solution {
public:
    int minPartitions(string n) 
    {
        int total = 0; // Minimum partitions

        for (char i : n) {
            if (i == '9') return 9; // If it's 9 then reached max and returns 9

            /* Subtract current minus the start of ASCII to get total
             * [------------------------------------
             *  Ex: 
             *      '0' = 48 -- ASCII Number of 0
             *      '3' = 51 -- ASCII Number of 3
             *
             *      3 - 0 = 3
             *      (51 - 48 = 3)
             * ------------------------------------]
             */
            // Compare if greater then max, If so then update to greatest value
            if (i - '0' > total) total = i - '0';
        }

        return total; // Return Max
    }
};

// REMINDER **
/* Not always the answer is the formula, but what it represents */
