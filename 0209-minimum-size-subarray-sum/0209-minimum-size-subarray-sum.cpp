class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        size_t n = nums.size();

        int ptr1 = 0;                 // left pointer
        int window_len = INT_MAX;     // answer (min length)
        int sum = 0;

        for (int ptr2 = 0; ptr2 < n; ptr2++)   // right pointer
        {
            sum += nums[ptr2];

            // shrink while sum is valid
            while (sum >= target) {
                window_len = min(window_len, ptr2 - ptr1 + 1);
                sum -= nums[ptr1];
                ptr1++;
            }
        }

        return (window_len == INT_MAX) ? 0 : window_len;
    }
};
