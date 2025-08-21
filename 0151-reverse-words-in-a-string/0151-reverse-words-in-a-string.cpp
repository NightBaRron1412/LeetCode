class Solution {
public:
    string reverseWords(string s) {
        string res = "";              // Final result string
        size_t n = s.size();          // Length of input string
        bool found_word = false;      // Flag to indicate if we are currently inside a word
        string word = "";             // Temporary buffer to store current word

        // Traverse the string backwards
        for (int i = n - 1; i >= 0; i--)
        {
            // Case 1: found the start of a new word (first non-space after spaces)
            if (s[i] != ' ' && !found_word)
            {
                found_word = true;    // Mark that we're inside a word
                word = "";            // Reset current word
            }
            // Case 2: reached a space after finishing a word
            else if (s[i] == ' ' && found_word)
            {
                found_word = false;   // Word ended
                if (!res.empty())     // If result already has words, add a space before appending new one
                {
                    res += ' ';
                }
                res += word;          // Append the completed word to result
            }

            // Case 3: collect characters of the current word
            if (s[i] != ' ' && found_word)
            {
                // Prepend current character (so word builds in correct order)
                word = s[i] + word;
            }
        }

        // Edge case: string started with a word and no space followed after
        if (found_word) {
            if (!res.empty()) res += ' ';
            res += word;              // Add the last word
        }

        return res;                   // Return the reversed words string
    }
};
