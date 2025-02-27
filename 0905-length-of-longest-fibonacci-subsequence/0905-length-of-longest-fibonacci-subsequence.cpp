class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
    unordered_set<int> numSet(arr.begin(), arr.end());
    size_t n = arr.size();
    int maxLength = 0;
    
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            int a = arr[i], b = arr[j], len = 2;
            
            while (numSet.find(a + b) != numSet.end()) {
                int temp = a + b;
                a = b;
                b = temp;
                len++;
                maxLength = max(maxLength, len);
            }
        }
    }
    
    return (maxLength >= 3) ? maxLength : 0;
}
};