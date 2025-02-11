class Solution {
public:
    string removeOccurrences(string s, const string& part) {
        size_t pos;
        size_t part_len = part.size();
        while ((pos = s.find(part)) != string::npos) {
            s.erase(pos, part_len);
        }
        return s;
    }
};
