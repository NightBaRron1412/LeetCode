class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
         int rows = grid.size(), cols = grid[0].size();
        int totalServers = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    bool hasNeighbor = false;

                    for (int col = 0; col < cols; ++col) {
                        if (col != c && grid[r][col] == 1) {
                            hasNeighbor = true;
                            break;
                        }
                    }

                    if (!hasNeighbor) {
                        for (int row = 0; row < rows; ++row) {
                            if (row != r && grid[row][c] == 1) {
                                hasNeighbor = true;
                                break;
                            }
                        }
                    }

                    if (hasNeighbor) {
                        totalServers++;
                    }
                }
            }
        }

        return totalServers;
    }
};

