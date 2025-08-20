class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;  // This will hold the resulting longest common prefix.
        size_t n = strs.size();  // Number of input strings.
        char comp_letter;  // The character to compare at the current index.
        int comp_letter_idx = 0;  // Current character index being checked.
        
        // Track the length of the shortest string in the list.
        // Initialize with INT_MAX so any string length will be smaller.
        int smallest_word_size = INT_MAX;

        // Find the size of the smallest string.
        for (string str : strs) {
            smallest_word_size = min(smallest_word_size, (int)str.size());
        }

        // Iterate through each character position up to the shortest string's length.
        while (comp_letter_idx < smallest_word_size) {
            // Take the current character from the first string as a reference.
            comp_letter = strs[0][comp_letter_idx];

            // Check if all strings have the same character at this index.
            for (string str : strs) {
                if (str[comp_letter_idx] != comp_letter) {
                    // If a mismatch is found, return the prefix built so far.
                    return res;
                }
            }

            // If all characters matched at this index, add it to the result.
            res.push_back(comp_letter);

            // Move to the next character index.
            comp_letter_idx++;
        }

        // Return the final longest common prefix.
        return res;
    }
};
