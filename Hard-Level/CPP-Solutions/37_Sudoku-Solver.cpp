class Solution {
private:
    const int ROWS_LENGTH = 9;
    const int COLUMNS_LENGTH = 9;

    vector<vector<bool>>& rows

    bool isValid(vector<vector<char>>& board, char input, int row, int column) {
        if (row == ROWS_LENGTH) return true;

        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == ROWS_LENGTH) {
            nextRow = row + 1;
            nextCol = 0;
        }

        for(int i = 1; i <= ROWS_LENGTH; i++) {
            return board[row][i]
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < ROWS_LENGTH; row++) {
            for (int column = 0; column < COLUMNS_LENGTH; column++) {

            }
        }
    }
};
