class Solution {
public:
    int minimumLength(string s) {
        vector <int> freq(26 , 0);
        size_t length {s.size()};
        for (size_t i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
        for (size_t i = 0; i < freq.size(); i++)
        {
            if (freq[i] > 2)
            {
                if (freq[i] % 2 == 0)
                {
                    length = length - freq[i] + 2;
                }
                else
                {
                    length = length - freq[i] + 1;
                }
            }
        }
        return length;
    }
};