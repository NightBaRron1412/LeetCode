class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos{0};
        size_t part_len = part.size();
        while (true)
        {
            pos = s.find(part);
            if (pos == string::npos)
            {
                break;
            }
            else
            {
                s.erase(pos, part_len);
            }
        }
        return s;
    }
};