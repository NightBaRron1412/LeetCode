class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // get the size of the input array
        size_t n = nums.size();
        vector<vector<int>> ans = {};

        // sort to use two pointers
        sort(nums.begin(), nums.end());

        // iterate pivot values by index
        for (int i = 0; i < n; ++i)
        {
            // skip duplicate pivots
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int num = nums[i];
            int target = 0 - num;

            // two pointers: one after pivot, one at the end
            int p1 = i + 1;
            int p2 = n - 1;

            // move the pointers toward each other
            while (p1 < p2)
            {
                // calculate the sum of the two numbers
                int sum = nums[p1] + nums[p2];

                // if the sum equals target, record the triplet
                if (sum == target)
                {
                    ans.push_back({num, nums[p1], nums[p2]});

                    // move both pointers and skip duplicates
                    int leftVal = nums[p1];
                    int rightVal = nums[p2];
                    while (p1 < p2 && nums[p1] == leftVal) ++p1;
                    while (p1 < p2 && nums[p2] == rightVal) --p2;
                }
                // if the sum is too small, move the left pointer forward
                else if (sum < target)
                {
                    ++p1;
                }
                // if the sum is too large, move the right pointer backward
                else
                {
                    --p2;
                }
            }
        }

        // return all unique triplets
        return ans;
    }
};
