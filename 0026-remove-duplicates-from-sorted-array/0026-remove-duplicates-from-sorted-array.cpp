class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> hist;
        int index {0};
        for (int i = 0; i < nums.size(); i++){
            if(hist.find(nums[i]) == hist.end()){
                nums[index++] = nums[i];
                hist[nums[i]] = 1;

            }
        }
        return index;
    }
};