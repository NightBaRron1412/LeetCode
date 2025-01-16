class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 {0}, xor2 {0}, res {0};

        for (size_t i = 0; i < nums1.size(); i++) {
            xor1 ^= nums1[i];
        }

        for (size_t j = 0; j < nums2.size(); j++) {
            xor2 ^= nums2[j];
        }

        if (nums2.size() % 2 != 0) {
            res ^= xor1;
        }

        if (nums1.size() % 2 != 0) {
            res ^= xor2;
        }

        return res;
    }
};