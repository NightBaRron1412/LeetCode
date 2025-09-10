class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t n = matrix.size(); // Number of rows/columns (matrix is n x n)

        // Step 1: Reverse the order of rows (vertical flip)
        reverse(matrix.begin(), matrix.end());

        // Step 2: Transpose the matrix (swap across the main diagonal)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // After these two steps, the matrix is rotated 90 degrees clockwise
    }
};
