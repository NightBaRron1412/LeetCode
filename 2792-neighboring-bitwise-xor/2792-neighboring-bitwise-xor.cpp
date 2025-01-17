class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        uint xor_sum {0};
        for (size_t i = 0; i < derived.size(); i++)
        {
            xor_sum ^= derived[i];
        }

        return !xor_sum;
    }
};