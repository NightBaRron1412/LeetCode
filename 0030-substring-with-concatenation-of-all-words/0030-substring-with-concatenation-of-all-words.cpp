class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans; // stores the starting indices of all valid substrings

        int win_step = words[0].size(); // length of each word (all words have equal length)
        int n = s.size();               // length of the input string
        int m = words.size();           // number of words
        int totalLen = win_step * m;    // total length of a valid concatenation

        // Map to count how many times each word is needed
        unordered_map<string,int> need;
        for (auto &w : words) {
            need[w]++;
        }

        // We try different offsets because substrings could start at different positions
        // relative to word length (e.g., 0, 1, 2... up to win_step - 1)
        for (int offset = 0; offset < win_step; offset++) {
            int left = offset;  // left boundary of the sliding window
            int count = 0;      // number of valid words matched so far
            unordered_map<string,int> seen; // counts words currently in the window

            // Slide the window by steps of `win_step`
            for (int right = offset; right + win_step <= n; right += win_step) {
                string w = s.substr(right, win_step); // extract current word

                if (need.count(w)) { // if the word is part of the required set
                    seen[w]++;       // increment its count
                    if (seen[w] <= need[w]) {
                        count++; // still within the required frequency
                    } else {
                        // Too many occurrences of this word -> shrink window from the left
                        while (seen[w] > need[w]) {
                            string pop = s.substr(left, win_step);
                            left += win_step;
                            seen[pop]--;
                            if (seen[pop] < need[pop]) count--;
                        }
                    }

                    // If all words are matched exactly
                    if (count == m) {
                        ans.push_back(left); // store the starting index
                        // Move left forward to look for new solutions
                        string pop = s.substr(left, win_step);
                        left += win_step;
                        seen[pop]--;
                        count--;
                    }
                } else {
                    // If the word isn’t needed, reset the window
                    seen.clear();
                    count = 0;
                    left = right + win_step;
                }
            }
        }

        return ans; // return all valid starting indices
    }
};
