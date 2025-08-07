class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p1 = 0; // a pointer that will replace items when the other pointer finds a new unique item
        int n = nums.size();

        for (int p2 = 0; p2 < n; p2++)
        {
            if (nums[p2] !=  nums[p1])
            {
                nums[++p1] = nums[p2];
            }
        }

        return p1 + 1;
    }
};