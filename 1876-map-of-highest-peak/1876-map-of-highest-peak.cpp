class Solution {
public:
    typedef pair<int, int> Cell;
    template<typename T>
    using Matrix = vector<vector<T>>;

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int rows = isWater.size();
        const int cols = isWater[0].size();

        Matrix<int> height(rows, vector<int>(cols, -1));
        queue<Cell> bfsQueue;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    bfsQueue.push(Cell(i, j));
                }
            }
        }

        const int directionOffsets[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!bfsQueue.empty()) {
            Cell current = bfsQueue.front();
            bfsQueue.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int newX = current.first + directionOffsets[dir][0];
                int newY = current.second + directionOffsets[dir][1];

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    if (height[newX][newY] == -1) {
                        height[newX][newY] = height[current.first][current.second] + 1;
                        bfsQueue.push(Cell(newX, newY));
                    }
                }
            }
        }

        return height;
    }
};