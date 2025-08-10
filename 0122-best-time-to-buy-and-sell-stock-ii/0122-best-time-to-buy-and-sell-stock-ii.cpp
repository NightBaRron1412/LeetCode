class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // If there are fewer than 2 days, you can't make any transaction.
        if (prices.size() < 2) return 0;

        // Track the price from the previous day (the "buy" for a 1-day window).
        int prev_price = prices[0];

        // Accumulates profit over multiple buy/sell pairs.
        int total_profit = 0;

        const size_t n = prices.size();
        for (size_t i = 1; i < n; ++i) {
            // If today's price is higher than yesterday's, take that gain.
            // Conceptually: buy yesterday, sell today, then "reset" the buy to today.
            if (prices[i] > prev_price) {
                total_profit += prices[i] - prev_price;
            }
            // Move the window forward: today's price becomes "yesterday" for the next step.
            prev_price = prices[i];
        }

        return total_profit; // Max profit with unlimited transactions.
    }
};
