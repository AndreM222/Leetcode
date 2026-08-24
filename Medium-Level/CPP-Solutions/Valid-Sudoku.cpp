// --------------------------------------------[ Boolean Lookup Table ]--------------------------------------------
// O(1)
class Solution {
private:
    const int dimension = 9;
    const int splits = 3;
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(dimension, vector<bool>(dimension, false));
        vector<vector<bool>> cols(dimension, vector<bool>(dimension, false));
        vector<vector<bool>> grid(dimension, vector<bool>(dimension, false));
        
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                if (board[i][j] == '.') continue;
                int gridIndex = (i / splits) * 3 + (j / splits);
                int num = board[i][j] - '1';
                if (rows[i][num] || cols[j][num] || grid[gridIndex][num]) return false;
                rows[i][num] = cols[j][num] = grid[gridIndex][num] = true;
            }
        }
        
        return true;
    }
};