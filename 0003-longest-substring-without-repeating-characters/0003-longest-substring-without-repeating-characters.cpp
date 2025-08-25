class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Sliding-window over s to keep a substring with all unique chars.
        // 'seen' tracks which characters are currently inside the window [ptr1..ptr2].
        unordered_set<char> seen;

        size_t n = s.size();
        int longest = 0;   // best window length found so far
        int ptr1 = 0;      // left boundary of the window

        for (int ptr2 = 0; ptr2 < (int)n; ptr2++)  // expand the window with ptr2
        {
            if (seen.find(s[ptr2]) == seen.end()) {
                // New character: extend window to the right
                seen.insert(s[ptr2]);
                longest = max(longest, ptr2 - ptr1 + 1);
            } else {
                // Duplicate found at s[ptr2].
                // Shrink window from the left until we pass the previous
                // occurrence of s[ptr2], ensuring uniqueness again.
                while (s[ptr1] != s[ptr2]) {
                    // Remove chars that leave the window
                    seen.erase(s[ptr1]);
                    ptr1++;
                }
                // Now s[ptr1] == s[ptr2] (the previous duplicate).
                // Move left past that previous occurrence so the window becomes unique.
                ptr1++;
                // Re-insert / ensure current right char is in the set for the new window.
                // (No effect if already present; keeps set consistent with the window.)
                seen.insert(s[ptr2]);

                // Update best length after adjusting the left boundary.
                longest = max(longest, ptr2 - ptr1 + 1);
            }
        }
        return longest;
    }
};
