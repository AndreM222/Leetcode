// O(NLogN+M)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string highest = "";

        // Sort to group equal ones and put end to end the different ones
        sort(strs.begin(), strs.end());

        // Get the two endpoints
        string left = strs.front(), right = strs.back();

        // Get shortest from the left and right for comparison
        int length = left.length() < right.length() ? left.length() : right.length();

        // Loop through words to get longest prefix
        for(int i = 0; i < length; i++)
        {
            // If equal then add character
            if(left[i] == right[i]) highest += left[i];
            else break; // Else we have the longest prefix
        }

        return highest;
    }
};
