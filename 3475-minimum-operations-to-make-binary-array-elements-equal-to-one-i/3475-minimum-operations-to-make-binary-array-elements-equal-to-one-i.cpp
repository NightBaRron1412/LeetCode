class Solution {
public:
    int minOperations(vector<int>& nums) {
        size_t n = nums.size();
        size_t ops_count {0};
        for (size_t i = 0; i < n - 2; i++)
        {
            if (nums[i] == 0)
            {
                flipBits(nums[i], nums[i + 1], nums[i + 2]);
                ops_count++;
            }
        }

        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] != 1)
            {
                return -1;
            }
        }

        return ops_count;
    }
private:
    void flipBits(int &a, int &b, int &c)
    {
        a ^= 1;
        b ^= 1;
        c ^= 1;
    }
};