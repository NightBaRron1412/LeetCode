class Solution {
public:
    int candy(vector<int>& ratings) {
        // Get the number of children
        size_t n = ratings.size();

        // Each child gets at least 1 candy initially
        vector<int> candies(n, 1);

        // Variable to accumulate total candies given (will be summed in second loop)
        int total_candies = 0;

        // First pass: left -> right
        // Ensures the rule: if a child has a higher rating than their left neighbor,
        // they must get more candies than that neighbor
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                // Give one more candy than the left neighbor
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Second pass: right -> left
        // Ensures the rule: if a child has a higher rating than their right neighbor,
        // they must get more candies than that neighbor
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                // Take the max to avoid decreasing candies assigned in the first pass
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }

            // Add candies for this child to the total
            total_candies += candies[i];
        }

        // Add the candies for the last child (index n-1) which wasn't included in the loop sum
        return total_candies + candies[n - 1];
    }
};
