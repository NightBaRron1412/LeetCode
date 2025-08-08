class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;               // Tracks the maximum profit found so far
        int min_price = INT_MAX;      // Tracks the lowest price seen so far
        size_t n = prices.size();     // Total number of days (prices)

        // Loop through each day's price
        for (int i = 0; i < n; i++)
        {
            // Update the lowest price if the current price is lower
            min_price = min(min_price, prices[i]);

            // Calculate the profit if we sold today (current price - lowest price so far)
            // and update the maximum profit if this is better
            profit = max(profit, prices[i] - min_price);
        }

        // Return the best profit possible with one buy and one sell
        return profit;
    }
};
