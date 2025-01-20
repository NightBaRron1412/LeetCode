class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        size_t rowSize {mat.size()};
        size_t colSize {mat[0].size()};
        unordered_map<int, int> indexMap {};
        for (int i = 0; i < arr.size(); i++) {
            indexMap[arr[i]] = i;
        }
        vector<int> rowCounter(rowSize, 0);
        vector<int> colCounter(colSize, 0);
        unordered_map<int, pair<int, int>> posMap {};
        for (size_t i = 0; i < rowSize; i++) {
            for (size_t j = 0; j < colSize; j++) {
                posMap[mat[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            auto [row, col] = posMap[arr[i]];
            rowCounter[row]++;
            colCounter[col]++;
            if (rowCounter[row] == colSize || colCounter[col] == rowSize) {
                return i;
            }
        }
        return -1;
    }
};
