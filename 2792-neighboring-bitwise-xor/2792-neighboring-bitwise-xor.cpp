class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        uint sum {0};
        sum = accumulate(derived.begin(), derived.end(), 0);
        __builtin_popcount(sum);

        return (sum % 2 == 0);
    }
};