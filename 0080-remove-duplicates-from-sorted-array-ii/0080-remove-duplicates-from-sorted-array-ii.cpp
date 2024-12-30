class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2){
            return nums.size();
        }
        for (size_t i = 1; i < nums.size(); i++){
            if (i != nums.size() - 1 && nums.at(i) == nums.at(i - 1) && nums.at(i) == nums.at(i + 1)){
                nums.erase(nums.begin() + i--);
            }
        }

        return nums.size();
    }
};