class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_ptr = 0;
        size_t n = s.size();
        size_t m = t.size();

        for (int i = 0; i < m; i++)
        {
            if (s[s_ptr] == t[i])
            {
                s_ptr++;
            }
        }
        return s_ptr >= n;
    }
};