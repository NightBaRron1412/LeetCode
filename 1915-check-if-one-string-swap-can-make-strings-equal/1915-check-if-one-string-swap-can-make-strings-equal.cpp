class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        size_t n {s1.size()};
        std::vector <int> s1FM (26, 0);
        std::vector <int> s2FM (26, 0);
        int count {0};

        for (size_t i = 0; i < n; i++)
        {
            if (s1[i] != s2[i]) {
                count++;

                if (count > 2)
                {
                    return false;
                }
            }

            s1FM[s1[i] - 'a']++;
            s2FM[s2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (s1FM[i] != s2FM[i])
            {
                return false;
            }
        }

        return true;
    }
};