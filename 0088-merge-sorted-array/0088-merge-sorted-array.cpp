class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i {0};
        int k {m - 1};
        for (size_t j = 0; j < m + n; j++){
            if (m == 0){
                nums1 = nums2;
                break;
            }
            if (i < n && nums1.at(j) > nums2.at(i)){
                nums1.insert(nums1.begin() + j, nums2.at(i++));
                nums1.pop_back();
                k++;
            }
            else if (i < n && j > k){
                cout << "Entering second case";
                nums1.insert(nums1.begin() + j, nums2.at(i++));
                nums1.pop_back();
            }
        }
    }
};