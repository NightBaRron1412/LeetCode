class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Initialize the first element as a candidate for majority.
        int majority_num = nums[0];
        int count = 1;
        size_t n = nums.size();

        // Iterate through the array to find the majority element
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == majority_num)
            {
                // If current element is the same as the candidate, increment count
                count++;
            }
            else {
                // If different, decrement count
                count--;

                // If count drops to 0, update candidate to current element
                if (count == 0)
                {
                    majority_num = nums[i];
                    count = 1;
                }
            }
        }

        // By Boyer-Moore Voting Algorithm, majority_num is guaranteed to be the majority element
        return majority_num;
    }
};