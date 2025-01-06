class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result(boxes.size(), 0);
        for (size_t i = 0; i < boxes.size(); i++){
            if (boxes[i] == '1'){
                for (size_t j = 0; j < boxes.size(); j++){
                    result[j] += abs(static_cast<int>(j - i));
                }
            }
        }

        return result;
    }
};