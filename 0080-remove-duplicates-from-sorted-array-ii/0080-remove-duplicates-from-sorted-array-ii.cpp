class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write_index {1};
        int count{1};

        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i - 1]){
                count = 0;
            }
            if(nums[write_index - 1] != nums[i] || count < 2){
                nums[write_index++] = nums[i];
                count++;
            }
        }
        return write_index;
    }
};