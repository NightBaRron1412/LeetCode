class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count {0};
        for (string word : words)
        {
            count++;
            for (size_t i = 0; i < pref.size(); i++)
            {
                if (pref[i] != word[i])
                {
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};