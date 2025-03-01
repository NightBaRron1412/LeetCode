class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        size_t n = nums.size();

        for (size_t i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        size_t insert_pos = 0;
        for (size_t i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[insert_pos]);
                insert_pos++;
            }
        }

        return nums;
    }
};
