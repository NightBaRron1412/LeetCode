class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p1 = 0; // a pointer that will replace items when the other pointer finds a new unique item
        int n = nums.size(); // number of elements inside nums

        for (int p2 = 0; p2 < n; p2++) // p2 is an iterator that iterates throught the array to look for unique elements
        {
            if (nums[p2] !=  nums[p1])
            {
                nums[++p1] = nums[p2]; // if the element is unique we replace the item at p1 with the item at p2 and we advance p1 to next loc
            }
        }

        return p1 + 1; // we move p when we find a new unique element so it should contain the number of unique elements + the first element in the array
    }
};