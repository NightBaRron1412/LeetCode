class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t n = nums.size();
        k %= n; // Reduce k to within array length (handles k > n)

        // Reverse the entire array
        reverse_range(0, n - 1, nums);
        // Reverse the first k elements (now at the front after step 1)
        reverse_range(0, k - 1, nums);
        // Reverse the remaining n - k elements
        reverse_range(k, n - 1, nums);
    }

private:
    // Reverse a section of the vector from index 'start' to index 'end'
    void reverse_range(int start, int end, vector<int>& vec)
    {
        while (end > start)
        {
            // Swap the elements at 'start' and 'end'
            swap(vec[start], vec[end]);
            start++;
            end--;
        }
    }
};
