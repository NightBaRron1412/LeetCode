class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        size_t n = nums.size();
        unordered_map<int, int> diff_count;

        for (size_t i = 0; i < n; i++) {
            int diff = i - nums[i];

            int good_pairs = diff_count[diff];

            count += i - good_pairs;

            diff_count[diff] = good_pairs + 1;
        }

        return count;
    }
};