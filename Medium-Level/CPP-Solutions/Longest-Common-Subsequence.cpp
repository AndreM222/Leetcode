// Too long to iterate but was my first thinking O(2^n)
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        return lcsRecursion(text1, text2); // Start Recursion
    }

private:
    int lcsRecursion(string text1, string text2, int pos1 = 0, int pos2 = 0)
    {
        if(text1.length() == pos1 || text2.length() == pos2) return 0; // if end of min array then return 0
        // If current characters are equal then increase by 1
        else if(text1[pos1] == text2[pos2]) return lcsRecursion(text1, text2, pos1 + 1, pos2 + 1) + 1; 
        else
        {
            int left = lcsRecursion(text1, text2, pos1 + 1, pos2); // return total sequence starting with next letter of array 1
            int right = lcsRecursion(text1, text2, pos1, pos2 + 1); // return total sequence starting with next letter of array 2

            return left > right ? left : right; // return greatest sequence
        }
    }
};

// less iteration time and space O(n^2)
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // Initialize Variables
        int length1 = text1.length();
        int length2 = text2.length();

        int total[length1 + 1][length2 + 1];


        // Set all slots = 0;
        for (int i = 0; i < length1 + 1; ++i) {
            for (int j = 0; j < length2 + 1; ++j) {
                total[i][j] = 0;
            }
        }

        // Parse through the slots words to find the common subsequence
        for (int i = 0; i < length1; ++i) {
            for (int j = 0; j < length2; ++j) {
                if (text1[i] == text2[j]) { // If equal than increase by 1
                    total[i + 1][j + 1] = total[i][j] + 1;
                }

                else {
                    // else compare with and set the greatest of the sequences
                    total[i + 1][j + 1] = total[i][j + 1] > total[i + 1][j] ? total[i][j + 1] : total[i + 1][j]; 
                }
            }
        }
        // Return longest subsequence
        return total[length1][length2];
    }
};
