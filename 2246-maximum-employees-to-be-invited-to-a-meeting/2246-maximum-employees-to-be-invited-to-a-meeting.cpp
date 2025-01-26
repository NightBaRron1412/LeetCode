class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> reversedGraph(n);
        for (int i = 0; i < n; ++i)
            reversedGraph[favorite[i]].push_back(i);

        auto bfs = [&](int start, unordered_set<int>& visitedNodes) {
            queue<pair<int, int>> q;
            q.push({start, 0});
            int maxDist = 0;
            while (!q.empty()) {
                auto [node, dist] = q.front();
                q.pop();
                for (int neighbor : reversedGraph[node]) {
                    if (visitedNodes.count(neighbor)) continue;
                    visitedNodes.insert(neighbor);
                    q.push({neighbor, dist + 1});
                    maxDist = max(maxDist, dist + 1);
                }
            }
            return maxDist;
        };

        int longestCycle = 0, twoCycleInvitations = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                unordered_map<int, int> visitedPersons;
                int current = i, distance = 0;
                while (true) {
                    if (visited[current]) break;
                    visited[current] = true;
                    visitedPersons[current] = distance++;
                    int next = favorite[current];
                    if (visitedPersons.count(next)) {
                        int cycleLength = distance - visitedPersons[next];
                        longestCycle = max(longestCycle, cycleLength);
                        if (cycleLength == 2) {
                            unordered_set<int> visitedNodes = {current, next};
                            twoCycleInvitations += 2 + bfs(next, visitedNodes) + bfs(current, visitedNodes);
                        }
                        break;
                    }
                    current = next;
                }
            }
        }
        return max(longestCycle, twoCycleInvitations);
    }
};
