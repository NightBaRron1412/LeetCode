class Solution {
public:
    bool canPartition(string s, int t) {
        if (s.empty() && t == 0) return true;
        if (t < 0) return false;
        for (int i = 0; i < (int)s.size(); i++) {
            string a = s.substr(0, i + 1);
            string b = s.substr(i + 1);
            int val = stoi(a);
            if (canPartition(b, t - val)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            if (canPartition(to_string(sq), i)) {
                result += sq;
            }
        }
        return result;
    }
};
