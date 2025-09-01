class Solution {
public:
    string minWindow(string s, string t) {
        string ans = ""; // final result: the smallest valid window substring

        size_t n = s.size();
        int left = 0;    // left pointer of the sliding window
        int best_len = INT_MAX;
        int best_start = 0;

    
        unordered_map<char, int> need; // required counts of each character in t
        unordered_map<char, int> seen; // current counts inside the sliding window

        // count how many of each character we need from t
        for (char c : t) {
            need[c]++;
        }

        int required = need.size(); // number of unique characters in t that must be present
        int done = 0;               // how many required chars are satisfied so far


        // expand the window using right pointer
        for (int right = 0; right < n; right++) {
            char c = s[right];
            seen[c]++; // add this character to the current window
            if (need.count(c) && seen[c] == need[c]) {
                done++; // one required char is fully satisfied
            }

            // shrink the window while all requirements are met
            for (; left <= right && done == required; left++) {

                best_len = min(best_len, right - left + 1);
                if (best_len == right - left + 1) {
                    best_start = left;
                }

                // pop the leftmost char to try and shrink further
                char pop = s[left];
                seen[pop]--;
                if (need.count(pop) && seen[pop] < need[pop]) {
                    done--; // no longer satisfies requirement
                }
            }
        }

        return best_len == INT_MAX ? "" : s.substr(best_start, best_len);
    }
};
