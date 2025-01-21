class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
    size_t n = grid[0].size();
    vector<long long> topPrefix(n, 0), bottomPrefix(n, 0);
    
    topPrefix[0] = grid[0][0];
    bottomPrefix[0] = grid[1][0];
    
    for (size_t i = 1; i < n; ++i) {
        topPrefix[i] = topPrefix[i - 1] + grid[0][i];
        bottomPrefix[i] = bottomPrefix[i - 1] + grid[1][i];
    }
    
    long long result = LLONG_MAX;
    
    for (size_t col = 0; col < n; ++col) {
        long long topRemaining = topPrefix[n - 1] - topPrefix[col];
        long long bottomRemaining = col > 0 ? bottomPrefix[col - 1] : 0;
        result = min(result, max(topRemaining, bottomRemaining));
    }
    
    return result;
    }
};