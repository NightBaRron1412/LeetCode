class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long minRank = *min_element(ranks.begin(), ranks.end());
        long long left = 0;
        long long right = minRank * (long long)cars * cars;
        long long result = -1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (can(ranks, cars, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
    bool can(vector<int>& ranks, int cars, long long mid) {
        long long total = 0;

        for (size_t i = 0; i < ranks.size(); i++){
            long long x = ((long long)sqrt((long double)mid / ranks[i]));
            total += x;
            if (total >= cars)
                return true;
        }
        return false;
    }
};