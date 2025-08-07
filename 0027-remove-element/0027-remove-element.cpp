class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p1 = 0; // a pointer that stops when we see the value we want to remove so we can replace it with the value from the other pointer
        size_t n = nums.size();

        for (int p2 = 0; p2 < n; p2++) //p2 is a pointer that iterates through nums
        {
            if (nums[p2] != val)
            {
                nums[p1++] = nums[p2]; // assign value from p2 to p1 and advance p1
            }
        }
        return p1; //since we only advance p1 when we see a value other than the value we want to remove it should has the count of other numbers
    }
};