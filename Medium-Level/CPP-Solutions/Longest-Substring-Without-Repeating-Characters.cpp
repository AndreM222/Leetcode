class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> list; // List of known character
        int lengthS = s.length(); // Length Of String
        int maxL = 0, left = 0; // Init left index and max length variables

        for(int right = 0; right < lengthS; right++) // Parse through string
        {
            while(list.find(s[right]) != list.end()) // If existent
            {
                list.erase(s[left]); // Remove existent charactes till mid point
                left++; // Increase length starting from repeated character
            }

            list.insert(s[right]); // Insert unkown characters to list

            maxL = max(right - left + 1, maxL); // Set Maximum length
        }

        return maxL;
    }
};
