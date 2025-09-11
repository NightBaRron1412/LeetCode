class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        int n = board.size();        // Number of rows
        int m = board[0].size();     // Number of columns

        // Directions to explore all 8 neighbors of a cell
        std::vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        std::vector<int> dy = {-1,  0,  1,-1, 1,-1, 0, 1};

        // First pass: Mark cells with transitional states
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int liveNeighbors = 0;

                // Count live neighbors (1 = currently alive, -1 = alive → dead)
                for (int d = 0; d < 8; ++d) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (board[ni][nj] == 1 || board[ni][nj] == -1) {
                            liveNeighbors++;
                        }
                    }
                }
                
                // Rule 1 & 3: Live cell dies by under/overpopulation
                if (board[i][j] == 1) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = -1; // Temporarily mark live → dead
                    }
                } 
                // Rule 4: Dead cell becomes alive by reproduction
                else if (board[i][j] == 0) {
                    if (liveNeighbors == 3) {
                        board[i][j] = 2; // Temporarily mark dead → live
                    }
                }
            }
        }

        // Second pass: Finalize the board states
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == -1) {
                    board[i][j] = 0; // Finalize live → dead
                } else if (board[i][j] == 2) {
                    board[i][j] = 1; // Finalize dead → live
                }
            }
        }
    }
};
