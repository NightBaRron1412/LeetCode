class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;

        for (int i = 0; i < n; ) {
            int j = i;
            int lineLength = 0, totalChars = 0;

            // Count how many words fit in the current line
            for (j = i; j < n && lineLength + words[j].size() + (j - i) <= maxWidth; ++j) {
                lineLength += words[j].size();
                totalChars += words[j].size();
            }

            int spaces = maxWidth - totalChars;     // total spaces to distribute
            int gaps = j - i - 1;                   // number of gaps between words
            string line;

            if (j == n || gaps == 0) {              // last line or single-word line
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k != j - 1) line += ' ';
                }
                for (int k = (int)line.size(); k < maxWidth; ++k) line += ' ';
            } else {
                int spaceEach = spaces / gaps;
                int extra = spaces % gaps;          // extra spaces from the left
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k != j - 1) {
                        int toAdd = spaceEach + (extra > 0 ? 1 : 0);
                        for (int s = 0; s < toAdd; ++s) line += ' ';
                        if (extra > 0) --extra;
                    }
                }
            }

            ans.push_back(std::move(line));
            i = j;                                   // move to next line
        }

        return ans;
    }
};
