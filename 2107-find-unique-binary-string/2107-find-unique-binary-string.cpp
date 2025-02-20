class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        size_t n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i][i] == '0')
            {
                res += '1';
            }
            else
            {
                res += '0';
            }
        }
        
        return res;
    }
};