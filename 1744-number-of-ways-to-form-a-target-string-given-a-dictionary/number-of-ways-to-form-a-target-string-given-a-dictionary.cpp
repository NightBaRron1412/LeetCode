class Solution {
public:
    
    // Modulo for large numbers
    #define MOD 1000000007
    
    int dfs(int tpos, int col, const string& target, const vector<vector<int>>& freq, map<pair<int, int>, int>& dp){

        // Base cases
        if (tpos == target.size()) // Successfully formed the target
        {
            return 1;
        } 
        if (col == freq.size()) // Reached the end of columns (words length)
        {
            return 0;
        }

        // Check if result is already computed
        if (dp.count({tpos, col}))
        {
            return dp[{tpos, col}];
        }

        // Current character in the target
        char c = target[tpos];

        // Skip the current column
        int ways = dfs(tpos, col + 1, target, freq, dp);

        // Include the current column if the character matches
        if (freq.at(col).at(c - 'a') > 0) {
            ways = (ways + (1LL * freq.at(col).at(c - 'a') * dfs(tpos + 1, col + 1, target, freq, dp)) % MOD) % MOD;
        }

        // Store the result in the memoization map
        dp[{tpos, col}] = ways;
        return ways;
    }

    int numWays(vector<string>& words, string target) {

        // Precompute the character frequencies at each column
        int word_len = words.at(0).size();
        vector<vector<int>> freq(word_len, vector<int>(26, 0)); // 26 for 'a' to 'z'

        for (size_t row = 0; row < words.size(); row++){
            for (size_t col = 0; col < word_len; col++){
                freq.at(col).at(words.at(row).at(col) - 'a')++;
            }
        }

        map<pair<int, int>, int> dp;

        return dfs(0, 0, target, freq, dp);

    }
};