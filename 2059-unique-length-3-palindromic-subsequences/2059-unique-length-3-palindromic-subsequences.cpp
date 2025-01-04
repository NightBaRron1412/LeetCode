class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> first, last;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (first.find(s[i]) == first.end()) {
                first[s[i]] = i;
            }
            last[s[i]] = i;
        }

        for (auto& [c, start] : first) {
            int end = last[c];
            if (end - start > 1) { 
                unordered_set<char> between(s.begin() + start + 1, s.begin() + end);
                count += between.size();
            }
        }

        return count;
    }
};
