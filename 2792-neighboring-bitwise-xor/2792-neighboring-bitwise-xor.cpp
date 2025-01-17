class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        uint xor_sum {0};
        size_t n {derived.size()};
        for (size_t i = 0; i < n; i++)
        {
            xor_sum ^= derived[i];
        }

        return !xor_sum;
    }
};