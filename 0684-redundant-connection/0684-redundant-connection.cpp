class Solution {
private:
    int cycleStart = -1;

    void explore(int node, vector<bool> &visited, vector<int> graph[], vector<int> &ancestor) {
        visited[node] = true;
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                ancestor[neighbor] = node;
                explore(neighbor, visited, graph, ancestor);
            } else if (neighbor != ancestor[node] && cycleStart == -1) {
                cycleStart = neighbor;
                ancestor[neighbor] = node;
            }
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int size = edges.size();
        
        vector<bool> visited(size, false);
        vector<int> ancestor(size, -1);
        vector<int> graph[size];
        
        for (auto edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        
        explore(0, visited, graph, ancestor);
        
        unordered_map<int, int> cycleElements;
        int current = cycleStart;
        
        do {
            cycleElements[current] = 1;
            current = ancestor[current];
        } while (current != cycleStart);
        
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (cycleElements[edges[i][0] - 1] && cycleElements[edges[i][1] - 1]) {
                return edges[i];
            }
        }
        
        return {};
    }
};
