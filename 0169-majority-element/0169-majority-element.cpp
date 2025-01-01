class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate {nums.at(0)};
        int count {1};

        for (size_t i = 1; i < nums.size(); ++i){
            nums.at(i) == candidate ? count++ : count--;
            if (count == 0)
             {
                candidate = nums.at(i);
                count = 1;
            }
        }
        return candidate;
    }
};