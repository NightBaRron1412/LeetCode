class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> ans(n, 1);

        // Prefix products
        for (size_t i = 1; i < n; i++) {
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        // Suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
