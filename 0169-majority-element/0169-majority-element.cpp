class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate {nums.at(0)};
        int count {1};

        for (int num : nums){
            num == candidate ? count++ : count--;
            if (count == 0)
             {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};