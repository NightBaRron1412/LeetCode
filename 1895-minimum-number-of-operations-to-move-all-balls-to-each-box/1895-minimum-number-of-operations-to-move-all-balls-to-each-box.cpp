class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> non_empty_boxes (0, boxes.size());
        vector<int> result (0, boxes.size());
        for (size_t i = 0; i < boxes.size(); i++){
            if (boxes[i] == '1'){
                non_empty_boxes.push_back(i);
            }
        }
        for (size_t i = 0; i < boxes.size(); i++){
            int ans {0};
            for (size_t j = 0; j < non_empty_boxes.size(); j++){
                ans += abs(static_cast<int>(i - non_empty_boxes[j]));
            }
            result.push_back(ans);
        }
        return result;
    }
};