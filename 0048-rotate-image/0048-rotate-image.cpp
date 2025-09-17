class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t n = matrix.size();      // number of rows
        size_t m = matrix[0].size();   // number of columns (same as n since it's a square matrix)

        // Step 1: Reverse the matrix vertically (top ↔ bottom)
        // Swap row i with row (n - 1 - i), for the top half only
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m; j++) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }

        // Step 2: Transpose the matrix (swap across the main diagonal)
        // For each element above the diagonal, swap it with its symmetric element
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
