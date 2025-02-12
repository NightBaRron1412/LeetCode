class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> digit_sums;
        for (int num : nums) {
            int sum = 0;
            for (char c : to_string(num)) {
                sum += c - '0';
            }
            digit_sums.emplace_back(sum, num);
        }
        sort(digit_sums.begin(), digit_sums.end());
        int max_sum = -1, prev_num = -1, prev_sum = -1;
        for (const auto& [sum, num] : digit_sums) {
            if (sum == prev_sum) {
                max_sum = max(max_sum, prev_num + num);
            }
            prev_sum = sum;
            prev_num = num;
        }
        return max_sum;
    }
};