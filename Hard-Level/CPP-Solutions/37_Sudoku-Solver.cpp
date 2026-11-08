// --------------------------------------------[ Using Recursion ]--------------------------------------------
// O(9^N)
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
        if (rowValues[row][index] || columnValues[column][index] ||
            blockValues[grid][index])
            return false;

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        bool rowValues[9][9] = {false};
        bool columnValues[9][9] = {false};
        bool blockValues[9][9] = {false};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int v = board[r][c] - '1';
                    rowValues[r][v] = true;
                    columnValues[c][v] = true;
                    blockValues[(r / 3) * 3 + (c / 3)][v] = true;
                }
            }
        }

        vector<pair<int, int>> emptyCells;
        set<char> possibles = {'1', '2', '3', '4', '5',
                                         '6', '7', '8', '9'};

        for (int row = 0; row < 9; row++) {
            for (int column = 0; column < 9; column++) {
                int grid = (row / 3) * 3 + (column / 3);

                if (board[row][column] == '.') {
                    for (char val : possibles) {
                        if (isValid(rowValues, columnValues, blockValues, row,
                                    column, grid, val)) {
                            board[row][column] = val;
                            possibles.erase(val);
                            emptyCells.push_back({row, column});
                            possibles = {'1', '2', '3', '4', '5',
                                         '6', '7', '8', '9'};
                            break;
                        }
                    }

                    if (board[row][column] == '.') {
                        if (emptyCells.empty()) return;
                        pair<int, int> lastItem = emptyCells.back();
                        emptyCells.pop_back();

                        int lastVal =
                            board[lastItem.first][lastItem.second] - '1';
                        grid = (lastItem.first / 3) * 3 + (lastItem.second / 3);

                        rowValues[lastItem.first][lastVal] = false;
                        columnValues[lastItem.second][lastVal] = false;
                        blockValues[grid][lastVal] = false;

                        possibles.clear();
                        for (int i = lastVal + 1; i < 9; ++i)
                            possibles.insert(static_cast<char>('1' + i));

                        if (lastItem.second <= 0) {
                            row = lastItem.first - 1;
                            column = 8;
                        } else {
                            row = lastItem.first;
                            column = lastItem.second - 1;
                        }

                        board[lastItem.first][lastItem.second] = '.';
                        continue;
                    };
                }

                int value = board[row][column] - '1';
                rowValues[row][value] = true;
                columnValues[column][value] = true;
                blockValues[grid][value] = true;
            }
        }
    }
};
