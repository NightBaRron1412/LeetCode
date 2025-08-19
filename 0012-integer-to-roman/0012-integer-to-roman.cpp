class Solution {
public:
    string intToRoman(int num) {
        // List of Roman numeral symbols ordered from largest to smallest
        vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        // Corresponding integer values for each Roman numeral symbol
        vector<int> int_map   = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        // Result string to build the Roman numeral
        string res = "";

        // Loop through each value-symbol pair
        for (int i = 0; i < int_map.size(); i++) {
            // While the remaining number is greater than or equal
            // to the current value, subtract it and append the symbol
            while (num >= int_map[i]) {
                res += roman[i];     // Append the Roman numeral string
                num -= int_map[i];   // Reduce the number by the mapped integer value
            }
        }

        // Return the final Roman numeral string
        return res;
    }
};
