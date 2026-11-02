class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string text : words) // Get words in array
        {
            for(int j = 0; j < text.length(); j++) // Get Characters from word
            {
                if (text[j] != text[text.length() - 1 - j]) break; // Compare if index in both starting left and right are equal, if no then skip word.
                if (j == text.length() - 1) return text; // If length is maxed and all letters are equal then return word
            }
        }

        return ""; // Return empty if none found
    }
};
