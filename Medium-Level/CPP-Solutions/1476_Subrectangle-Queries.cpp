class SubrectangleQueries {

private:
    vector<vector<int>> dimensions; // Rectangle container
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        dimensions = rectangle; // Set pointer to rectangle in global
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; i++) // Row1 to row2
        {
            for (int j = col1; j <= col2; j++) // Column1 to column2
            {
                dimensions[i][j] = newValue; // Change value of index
            }
        }
    }
    
    int getValue(int row, int col) {
        return dimensions[row][col]; // Return index
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
