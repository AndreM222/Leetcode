// --------------------------------------------[ Exponents and Loops ]--------------------------------------------
// O(log^2(n))
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        int8_t positive = -1, counter = 0;
        if(dividend < 0 == divisor < 0) positive = 1;

        long value = 0, top = abs((long)dividend), bottom = abs((long)divisor);

        while(top >= bottom) {
            counter = 0;

            while(top >= bottom << counter) counter++;
            counter--;

            top -= bottom << counter;
            value += 1L << counter;
        }

        value *= positive;

        if(value > INT_MAX) return INT_MAX;
        if(value < INT_MIN) return INT_MIN;

        return value;
    }
};
