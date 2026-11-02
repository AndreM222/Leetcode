// This is O(n^2) all the time
/*
 * This process is pretty Slow using a the prcoess of looking in
 * every index for possible palindromes till reached end of string
 * from startinf index point i to end of string.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        string longest = ""; // Initialize longest palindrome
        int lengthS = s.length(); // Length of string
        string straight; // Straight string
        string reversed; // Reversed string

        for(int i = 0; i < lengthS; i++)
        {
            straight = ""; // Restart straight string
            reversed = ""; // Restart reversed string
            for(int j = i; j < lengthS; j++)
            {
                straight = straight + s[j]; // Add character in order
                reversed = s[j] + reversed; // Add character in reverse
                if(straight == reversed) { // Compare if palindrome
                    if(straight.length() > longest.length()) longest = straight; // return longest palindrome
                }
            }
        }

        return longest; // Return longest palindrome
    }
};

/*
* This is a solution which grows from the center instead so it can
* skip unnecesary checks by skipping the process of the code on top
* and stop searching in current index the moment the word stops
* being a palindrome
*/
class Solution {
private:
    string currPalindrome(string s, int left, int right)
    {
        int lengthS = s.length(); //
        while(left >= 0 && right < lengthS && s[left] == s[right]) // Increase radius while still valid
        {
            right++;
            left--;
        }

        return s.substr(left + 1, right - left - 1); // Return longest palindrome from curr index
    }
public:
    string longestPalindrome(string s) {
        int lengthS = s.length(); // Length of string

        if(lengthS <= 1) return s; // Return s if length less or equal to 1

        string longest = s.substr(0, 1); // Longest Palindrome initialized with first letter
        string odd, even; // Even and Odd palindromes

        for(int i = 0; i < lengthS - 1; i++)
        {
            odd = currPalindrome(s, i, i); // Setup odd number palindrome search
            even = currPalindrome(s, i, i + 1); // Setup even number palindrome search

            if(odd.length() > longest.length()) longest = odd; // set highest palindrome
            if(even.length() > longest.length()) longest = even; // Set highest palindrome
        }

        return longest;
    }
};
