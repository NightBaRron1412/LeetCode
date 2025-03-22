class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (size_t i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n, false);
        
        int completeCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                
                dfs(adj, visited, i, component);
                
                if (isCompleteComponent(adj, component)) {
                    completeCount++;
                }
            }
        }
        
        return completeCount;
    }
    
private:
    void dfs(const vector<vector<int>>& adj, vector<bool>& visited, int node, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        
        for (size_t i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]]) {
                dfs(adj, visited, adj[node][i], component);
            }
        }
    }
    
    bool isCompleteComponent(const vector<vector<int>>& adj, const vector<int>& component) {
        int componentSize = component.size();
        
        for (size_t i = 0; i < componentSize; i++) {
            int currentNode = component[i];
            int edgesInComponent = 0;
            
            for (size_t j = 0; j < adj[currentNode].size(); j++) {
                if (find(component.begin(), component.end(), adj[currentNode][j]) != component.end()) {
                    edgesInComponent++;
                }
            }
            
            if (edgesInComponent != componentSize - 1) {
                return false;
            }
        }
        
        return true;
    }
};