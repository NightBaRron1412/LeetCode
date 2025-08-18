class Solution {
public:
    int trap(vector<int>& height) {
        size_t n = height.size();
        // Two-pointer approach: track highest walls seen from left and right.
        // NOTE: If n == 0, n-1 would underflow; guard in production code.

        int left_ptr = 0;                 // start from the left end
        int right_ptr = n - 1;            // start from the right end
        int left_max = height[0];         // highest wall seen so far from the left
        int right_max = height[n - 1];    // highest wall seen so far from the right
        int water = 0;                    // total trapped water

        // Move the pointer with the smaller boundary, because that side
        // determines the maximum possible water level at that step.
        while (left_ptr < right_ptr)
        {
            if (right_max > left_max)
            {
                // The left side is the bottleneck; we can safely compute water at left_ptr+1
                left_ptr++;
                // Update the best left boundary so far
                left_max = max(left_max, height[left_ptr]);
                // Water above this bar is (left_max - height[left_ptr]) if positive
                water += left_max - height[left_ptr];
            }
            else
            {
                // The right side is the bottleneck; compute water at right_ptr-1
                right_ptr--;
                // Update the best right boundary so far
                right_max = max(right_max, height[right_ptr]);
                // Water above this bar is (right_max - height[right_ptr]) if positive
                water += right_max - height[right_ptr];
            }
        }

        return water; // Total trapped water
    }
};
