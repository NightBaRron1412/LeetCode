class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefix_sum(nums.size());
        prefix_sum[0] = nums[0];
        for (size_t i = 1; i < prefix_sum.size(); i++){
             prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        int valid_splits {0};

        for (size_t i = 0; i < prefix_sum.size() - 1; i++){
            if (prefix_sum[i] >= (prefix_sum.back() - prefix_sum[i])){
                valid_splits++;
            }
        }

        return valid_splits;
    }
};