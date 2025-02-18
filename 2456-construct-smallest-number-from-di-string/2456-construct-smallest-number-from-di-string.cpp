class Solution {
public:
    string smallestNumber(string pattern) {
        string res;
        stack<int> num_stack;
        size_t n = pattern.size();

        for (size_t i = 0; i <= n ; i++) {
            num_stack.push(i + 1);

            if (i == n || pattern[i] == 'I') {
                while (!num_stack.empty()) {
                    res += to_string(num_stack.top());
                    num_stack.pop();
                }
            }
        }

        return res;
    }
};