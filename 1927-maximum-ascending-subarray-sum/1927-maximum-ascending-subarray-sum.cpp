class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum {nums[0]};
        size_t nums_size = nums.size();
        int maximum_sum = 0;
        for (size_t i = 1; i < nums_size; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                sum += nums[i];
            }else
            {
                maximum_sum = max(maximum_sum, sum);
                sum = nums[i];
            }
        }
        maximum_sum = max(maximum_sum, sum);
        return maximum_sum;
    }
};