// Too long to iterate but was my first thinking O(2^n)
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        return lcsRecursion(text1, text2);
    }

private:
    int lcsRecursion(string text1, string text2, int pos1 = 0, int pos2 = 0)
    {
        if(text1.length() == pos1 || text2.length() == pos2) return 0;
        else if(text1[pos1] == text2[pos2]) return lcsRecursion(text1, text2, pos1 + 1, pos2 + 1) + 1;
        else 
        {
            int left = lcsRecursion(text1, text2, pos1 + 1, pos2);
            int right = lcsRecursion(text1, text2, pos1, pos2 + 1);

            return left > right ? left : right;
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
                if (text1[i] == text2[j]) {
                    total[i + 1][j + 1] = total[i][j] + 1;
                }

                else {
                    total[i + 1][j + 1] = total[i][j + 1] > total[i + 1][j] ? total[i][j + 1] : total[i + 1][j];
                }
            }
        }
        // Return longest subsequence
        return total[length1][length2];
    }
};
