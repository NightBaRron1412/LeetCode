class Solution {
public:
    bool isPrerequisite(unordered_map<int, vector<int>>& adjList,
                        vector<bool>& visited, int src, int target) {
        visited[src] = true;
        if (src == target) return true;
        for (auto adj : adjList[src]) {
            if (!visited[adj] && isPrerequisite(adjList, visited, adj, target)) {
                return true;
            }
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<bool> result;
        for (auto q : queries) {
            vector<bool> visited(numCourses, false);
            result.push_back(isPrerequisite(adjList, visited, q[0], q[1]));
        }

        return result;
    }
};
