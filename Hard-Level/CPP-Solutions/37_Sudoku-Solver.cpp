class Solution {
private:
    const int ROWS_LENGTH = 9;
    const int ROWS_SPLITS = 3;
    const int COLUMNS_LENGTH = 9;
    const int COLUMNS_SLITS = 3;

    bool isValid(bool (&rowValues)[9][9], bool (&columnValues)[9][9],
                 bool (&blockValues)[9][9], int row, int column, int grid,
                 char input) {

        int index = input - '1';
        cout << "test Val: " << index << endl;
        if (rowValues[row][index] * columnValues[column][index] * blockValues[grid][index])
            return false;

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        bool rowValues[9][9] = {false};
        bool columnValues[9][9] = {false};
        bool blockValues[9][9] = {false};

        for (int row = 0; row < 9; row++) {
            unordered_set<char> possibles = {'0', '1', '2', '3', '4',
                                   '5', '6', '7', '8', '9'};

            for (int column = 0; column < 9; column++) {
                int value = board[row][column] - '1';
                int grid = (row / 3) * 3 + (column / 3);

                if (board[row][column] != '.') {
                    rowValues[row][value] = true;
                    columnValues[column][value] = true;

                    blockValues[grid][value] = true;
                    continue;
                }

                for (char val : possibles) {
                    if (isValid(rowValues, columnValues, blockValues, row,
                                column, grid, val)) {
                        board[row][column] = val;
                        possibles.erase(val);
                        break;
                    }
                }
            }
        }
    }
};
