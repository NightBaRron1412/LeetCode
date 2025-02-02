class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        size_t nums_size = nums.size();
        
        for (size_t i = 0; i < nums_size; i++) {
            if (nums[i] > nums[(i + 1) % nums_size]) {
                count++;
            }
        }

        return count <= 1;
    }
};
