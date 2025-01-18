class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        deque<pair<int, int>> dq;
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        dq.push_front({0, 0});
        cost[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i].first;
                int ny = y + directions[i].second;
                int new_cost = cost[x][y] + (grid[x][y] != i + 1);

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && new_cost < cost[nx][ny]) {
                    cost[nx][ny] = new_cost;
                    if (grid[x][y] == i + 1) {
                        dq.push_front({nx, ny});
                    } else {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};