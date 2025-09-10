class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Number of rows in the matrix
        size_t n = matrix.size();
        // Number of columns in the matrix
        size_t m = matrix[0].size();

        // Boolean array to mark which rows should be zeroed
        vector<bool> rows(n, false);
        // Boolean array to mark which columns should be zeroed
        vector<bool> cols(m, false);

        // First pass: identify all rows and columns that contain at least one zero
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (matrix[row][col] == 0) {
                    rows[row] = true;   // mark this row
                    cols[col] = true;   // mark this column
                }
            }
        }

        // Second pass: set cells to zero if they are in a marked row or column
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (rows[row] || cols[col]) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};
