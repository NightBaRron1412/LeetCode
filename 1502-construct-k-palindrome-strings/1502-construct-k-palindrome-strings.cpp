class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int odd_count = 0;
        for (auto& entry : freq) {
            if (entry.second % 2 != 0) {
                odd_count++;
            }
        }
        
        return odd_count <= k && s.length() >= k;
    }
};
