class Solution {
public:
    int trap(vector<int>& height) {
        size_t n = height.size();
        int left_ptr = 0;
        int right_ptr = n - 1;
        int left_max = height[0];
        int right_max = height[n - 1];
        int water = 0;

        while (left_ptr < right_ptr)
        {
            if(right_max > left_max)
            {
                left_ptr++;
                left_max = max(left_max, height[left_ptr]);
                water += left_max - height[left_ptr];
            }
            else
            {
                right_ptr--;
                right_max = max(right_max, height[right_ptr]);
                water += right_max - height[right_ptr];
            }
        }

        return water;

    }
};