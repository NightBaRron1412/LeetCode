class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> reverseAdj(n);

        for (int i = 0; i < n; i++) {
            for (int node : graph[i]) {
                reverseAdj[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> nodesQueue;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) nodesQueue.push(i);
        }

        vector<bool> isSafe(n, false);
        while (!nodesQueue.empty()) {
            int current = nodesQueue.front();
            nodesQueue.pop();
            isSafe[current] = true;
            for (int neighbor : reverseAdj[current]) {
                if (--indegree[neighbor] == 0) nodesQueue.push(neighbor);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (isSafe[i]) result.push_back(i);
        }
        return result;
    }
};
