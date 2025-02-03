class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        size_t nums_size = nums.size();
        if (nums_size == 0) return 0;

        int longest = 1;
        int count = 1;
        bool increasing = false;
        bool decreasing = false;

        for (size_t i = 1; i < nums_size; i++) {
            if (nums[i] > nums[i - 1]) {
                if (decreasing) {
                    count = 1;
                    decreasing = false;
                }
                increasing = true;
                count++;
            } else if (nums[i] < nums[i - 1]) {
                if (increasing) {
                    count = 1;
                    increasing = false;
                }
                decreasing = true;
                count++;
            } else {
                count = 1;
                increasing = false;
                decreasing = false;
            }
            longest = max(longest, count);
        }

        return longest;
    }
};
