class Solution {
public:
    unordered_map<int, int> memo;

    int dfs(int index, vector<int>& days, vector<int>& costs) {
        if (index >= days.size()) {
            return 0;
        }
        if (memo.count(index)) {
            return memo[index];
        }
        
        int cost1 = costs[0] + dfs(index + 1, days, costs);
        
        int nextIndex = index;
        while (nextIndex < days.size() && days[nextIndex] < days[index] + 7) {
            nextIndex++;
        }
        int cost7 = costs[1] + dfs(nextIndex, days, costs);
        
        nextIndex = index;
        while (nextIndex < days.size() && days[nextIndex] < days[index] + 30) {
            nextIndex++;
        }
        int cost30 = costs[2] + dfs(nextIndex, days, costs);
        
        return memo[index] = min({cost1, cost7, cost30});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return dfs(0, days, costs);
    }
};
