class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        
        int score {0};
        int zeros {0};
        for (size_t i = 0; i < s.size() - 1; i++) {
            s[i] == '1'? ones-- : zeros++;
            score = max(score, zeros + ones);
        }
        return score;
    }
};