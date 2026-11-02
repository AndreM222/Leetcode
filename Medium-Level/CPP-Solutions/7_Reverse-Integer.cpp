class Solution {
public:
    int reverse(int x) {
        long reversed = 0;

        while(x)
        {
            reversed = (reversed * 10) + (x % 10); // Get last digit from right and add to the right of the reversed
            x /= 10; // Remove last digit from right in the normal int
            if(reversed > INT_MAX || reversed < INT_MIN) return 0; // Check it is in 32 bits range if not than return 0
        }

        return reversed; // Return reversed
    }
};
