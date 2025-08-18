class Solution {
public:
    int romanToInt(string s) {
        int res = 0;                     // Result accumulator
        size_t n = s.size();             // Length of the Roman numeral string

        // Mapping of Roman numeral characters to their integer values
        unordered_map<char, int> roman_to_int = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        // Traverse each character except the last one
        for (int i = 0; i < n - 1; i++)
        {
            // If current value < next value, it's a subtractive notation (e.g., IV = 4)
            if (roman_to_int[s[i]] < roman_to_int[s[i + 1]])
            {
                res -= roman_to_int[s[i]];  // Subtract current value
            }
            else
            {
                res += roman_to_int[s[i]];  // Otherwise, add current value
            }
        }

        // Always add the value of the last character
        res += roman_to_int[s[n - 1]];

        return res;  // Final integer value
    }
};
