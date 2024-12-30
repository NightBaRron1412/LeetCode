class Solution {
public:
    #define MOD 1000000007
    int countGoodStrings(int low, int high, int zero, int one) {
    unordered_map<int, int> dp;
    return dfs(0, high, low, zero, one, dp);

    }

    int dfs(int length, int&  high, int&  low, int&  zero, int&  one, unordered_map<int, int>& dp){
        int  res {0};
        if (length > high){
            return 0;
        }

        if (dp.find(length) != dp.end()){
            return dp.at(length);
        }

        if (length >= low){
            res = 1;
        }
        
        res = (res + dfs(length + zero, high, low, zero, one, dp)) % MOD;
        res = (res + dfs(length + one, high, low, zero, one, dp)) % MOD;

        dp[length] = res;
        return res;
    }

};