class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        size_t n = s.size();
         unordered_map<char, int> roman_to_int = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for (int i = 0; i < n - 1; i++)
        {
            if (roman_to_int[s[i]] < roman_to_int[s[i + 1]])
            {
                res -= roman_to_int[s[i]];
            }
            else
            {
                res += roman_to_int[s[i]];
            }
        }

        res += roman_to_int[s[n - 1]];

        return res;
    }
};