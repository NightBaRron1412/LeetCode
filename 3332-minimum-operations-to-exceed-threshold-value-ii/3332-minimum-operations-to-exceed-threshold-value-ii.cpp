#include <vector>
#include <queue>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap(nums.begin(), nums.end());

        int count = 0;

        while (minHeap.top() < k) {
            long long x = minHeap.top();
            minHeap.pop();

            long long y = minHeap.top();
            minHeap.pop();

            long long new_value = x * 2LL + y;
            minHeap.push(new_value);
            count++;
        }

        return count;
    }
};