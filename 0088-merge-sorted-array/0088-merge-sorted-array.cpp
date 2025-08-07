class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1; // points to last element in  nums1
        int p2 = n - 1; // points to last element in nums2
        int i = m + n - 1; // iterator to iterate through nums1

        while (p2 >= 0)
        {
            if (p1 >= 0 && nums1[p1] > nums2[p2])
            {
                nums1[i] = nums1[p1--];
            } else {
                nums1[i] = nums2[p2--];
            }

            i--; // move iterator to next pos
        }
    }
};