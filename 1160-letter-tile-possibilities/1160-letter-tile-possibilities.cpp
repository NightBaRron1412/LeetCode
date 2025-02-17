class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char ch : tiles) {
            freq[ch]++;
        }
        int count = 0;
        dfs(freq, count, 0);
        return count;
    }
private:
    void dfs(unordered_map<char, int>& freq, int& count, int length) {
        for (auto& [ch, freqCount] : freq) {
            if (freqCount > 0) {
                count++;
                freq[ch]--;
                dfs(freq, count, length + 1);
                freq[ch]++;
            }
        }
    }
};