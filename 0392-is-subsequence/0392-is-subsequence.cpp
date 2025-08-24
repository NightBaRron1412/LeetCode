class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Pointer to track current position in string s
        int s_ptr = 0;

        // Lengths of strings s and t
        size_t n = s.size();
        size_t m = t.size();

        // Iterate through each character of string t
        for (int i = 0; i < m; i++)
        {
            // If the current character in t matches the current character in s
            if (s_ptr < n && s[s_ptr] == t[i]) // ✅ guard ensures we don't go out of bounds
            {
                // Move pointer forward in s to look for the next character
                s_ptr++;
            }
        }

        // If we've matched all characters of s (s_ptr reached n), then s is a subsequence of t
        return s_ptr >= n;
    }
};
