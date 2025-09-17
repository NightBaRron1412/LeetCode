class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t n = nums.size();   // Get the size of the array
        int left = 0;             // Left pointer
        int right = n - 1;        // Right pointer

        // Standard binary search loop
        while (left <= right)
        {
            int mid = (left + right) / 2;  // Find the middle index

            // If target is found, return its index
            if (nums[mid] == target)
            {
                return mid;
            }

            // Check if the left half [left..mid] is sorted
            if (nums[mid] >= nums[left])
            {
                // If target lies within the sorted left half
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;   // Discard the right half
                } else {
                    left = mid + 1;    // Discard the left half
                }
            }
            // Otherwise, the right half [mid..right] must be sorted
            else {
                // If target lies within the sorted right half
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;    // Discard the left half
                } else {
                    right = mid - 1;   // Discard the right half
                }
            }
        }

        // Target not found
        return -1;
    }
};
