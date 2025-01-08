class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count {0};
        for (size_t i = 0; i < words.size(); i++)
        {
            for (size_t j = i; j < words.size(); j++)
            {
                if (words[i].size() <=  words[j].size() && i != j)
                {
                    count += isPrefixAndSuffix(words[i], words[j]);
                }
            }
        }
        return count;
    }

private:
    bool isPrefixAndSuffix (string str1, string str2)
    {
        bool res {true};
        for (size_t i = 0; i < str1.size(); i++)
        {
            if (str1[i] != str2[i] || *(str1.end() - 1 - i) != *(str2.end() - 1 - i))

            {
                res = false;
            }
        }

        return res;
    }
};