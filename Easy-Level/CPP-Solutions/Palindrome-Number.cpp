class Solution 
{
public:
    bool isPalindrome(int x)
    {
        string text = to_string(x);
        int length = text.length();

        for(int j = 0; j < length; j++)
        {
            if(text[j] != text[length - 1 - j]) return false;
        }

        return true;
    }
};
