class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t n = haystack.size();   // length of the haystack string
        size_t m = needle.size();     // length of the needle string

        if (n < m) {
            return -1; // If pattern is longer than text, it can't occur
        }


        // Iterate through haystack, checking each possible starting position
        for (int i = 0; i <= n - m; i++)
        {
            // If the current haystack character doesn't match the first needle character, skip
            if (haystack[i] != needle[0])
            {
                continue;
            }

            // Try to match the full needle starting at position i
            for (int j = 0; j < m; j++)
            {
                // If characters don't match, break out of the inner loop
                if (needle[j] != haystack[i + j])
                {
                    break;
                }

                // If we reached the last character of needle and all matched, return start index
                if (j == m - 1)
                {
                    return i;
                }
            }
        }

        // If no match is found, return -1
        return -1;
    }
};
