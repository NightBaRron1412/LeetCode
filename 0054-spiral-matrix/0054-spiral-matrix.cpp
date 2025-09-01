class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();        // number of rows
        int m = matrix[0].size();     // number of columns

        int x = 0, y = 0;             // start position
        int dx = 1, dy = 0;           // initial direction → right

        vector<int> res;

        for (int num = 0; num < n * m; num++) {
            res.push_back(matrix[y][x]);   // take element
            matrix[y][x] = INT_MAX;        // mark visited

            // compute next step
            int nextX = x + dx;
            int nextY = y + dy;

            // check if next is invalid
            bool outOfBounds =  (nextX < 0 || nextX >= m ||
                                 nextY < 0  || nextY >= n);
            bool visited = !outOfBounds && matrix[nextY][nextX] == INT_MAX;

            if (outOfBounds || visited) {
                // rotate direction clockwise using swap
                swap(dx, dy);
                dx = -dx;
            }

            // move forward
            x += dx;
            y += dy;
        }

        return res;
    }
};
