class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff(s.size() + 1, 0);

        for (vector<int> shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] ? 1 : -1;

            diff[start] += direction;
            diff[end + 1] -= direction;
        }

        int cumulativeShift = 0;
        for (int i = 0; i < s.size(); ++i) {
            cumulativeShift += diff[i];
            int newChar = (s[i] - 'a' + cumulativeShift) % 26;
            if (newChar < 0) newChar += 26;
            s[i] = 'a' + newChar;
        }

        return s;
    }
};
