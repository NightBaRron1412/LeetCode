class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Pointer p1 indicates the position to place the next allowed element.
        // We start from index 2 since up to two duplicates are allowed.
        int p1 = 2;
        int n = nums.size(); // Total number of elements in the array.

         if (n <= 2)
         {
            return n; // If size is 2 or less, all elements are valid
         }

        // Iterate through the array starting from index 0
        for (int p2 = 2; p2 < n; p2++) {
            // Check if current element is different from the element two positions before p1.
            // This ensures no more than two duplicates are allowed.
            if (nums[p2] != nums[p1 - 2]) {
                // Place the valid element at position p1 and increment p1
                nums[p1++] = nums[p2];
            }
        }

        // p1 is the new length of the array after limiting duplicates to at most two
        return p1;
    }
};