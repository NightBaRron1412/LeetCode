class Solution {
public:
    bool canConstruct(string s, int k) {
        int freq[26] = {0};
        
        for (char c : s) {
            freq[c - 'a']++;
        }

        int odd_count = 0;
        for (int count : freq) {
            if (count % 2 != 0) {
                odd_count++;
            }
        }
        
        return odd_count <= k && s.length() >= k;
    }
};