class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Majority Voting Algorithm
        int majority_num = nums[0];
        int count = 1;
        size_t n = nums.size();

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == majority_num)
            {
                count++;
            }
            else {
                count--;
                if (count == 0)
                {
                    majority_num = nums[i];
                    count = 1;
                }
            }
            
        }

        return majority_num;
    }
};