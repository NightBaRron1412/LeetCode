class Solution {
public:
    string convert(string s, int numRows) {

        // Edge case: If only 1 row OR number of rows >= string length,
        // zigzag pattern is unnecessary, return the original string.
        if (numRows == 1 || numRows >= s.size())
        {
            return s;
        }

        string res = "";                     // Final result string
        vector<string> rows(numRows);        // Container to hold characters row by row
        size_t n = s.length();               // Length of input string
        int dir = -1;                        // Direction flag: -1 (up) or +1 (down)
        int idx = 0;                         // Current row index

        // Traverse through all characters in input string
        for (int i = 0; i < n; i++)
        {
             rows[idx].push_back(s[i]);      // Place current character in the correct row

             // If we are at the first row or last row, reverse the direction
             if (idx == 0 || idx == numRows - 1)
             {
                dir *= -1;
             }

             // Move to the next row depending on direction
             idx += dir;
        }

        // Combine all rows into the final result
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < rows[i].size(); j++)
            {
                res.push_back(rows[i][j]);   // Append each character from row to result
            } 
        }

        return res;                          // Return zigzag-converted string
    }
};
