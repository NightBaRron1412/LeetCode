class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Pointer p1 marks the position to place the next unique element.
        // Start from index 1 since the first element is always unique.
        int p1 = 1;
        int n = nums.size(); // Total number of elements in the array.

        // Traverse the array with p2 to find unique elements.
        for (int p2 = 0; p2 < n; p2++) {
            // If the current element is different from the last added unique element
            if (nums[p2] != nums[p1 - 1]) {
                // Place the new unique element at p1 and move p1 forward
                nums[p1++] = nums[p2];
            }
        }

        // p1 represents the length of the array with duplicates removed
        return p1;
    }
};
