class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        size_t n = nums.size();
        sort(nums.begin(), nums.end());

        int count {0};

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= i + 1; j--) {
                int product = nums[i] * nums[j];

                unordered_set<int> d_values;

                for (int k = i + 1; k < j; k++) {
                    if (product % nums[k] == 0) {
                        int d_value = product / nums[k];

                        if (d_values.find(d_value) !=
                            d_values.end()) {
                            count += 8;
                        }

                        d_values.insert(nums[k]);
                    }
                }
            }
        }

        return count;
    }
};