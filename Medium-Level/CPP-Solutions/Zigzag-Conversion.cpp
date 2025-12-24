// O(n)
class Solution {
public:
    string convert(string s, int numRows) {
        string text = "";
        vector<string> table;

        int y = -1;
        bool down = true;

        // Setup table for zig zag string
        for(int i = 0; i < numRows; i++) table.push_back("");

        // Parse through text and setup in table
        // in zig zag form
        for(char curr : s)
        {
            if(down) // Setup downward strings
            {
                if(y < numRows - 1) y++;
                table[y] += curr;
            } else { // Setup upward strings
                if(y > 0) y--;
                table[y] += curr;
            }

            // Switch direction when reached ends
            if((!down && !y) || (down && y == numRows - 1)) down = !down;
        }

        // Combine in order the rows
        for(string curr : table) text += curr;

        return text;
    }
};
