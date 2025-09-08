class Solution {
public:
    // Main function to split n into two positive integers without any zero digits
    vector<int> getNoZeroIntegers(int n) {
        int first = 1; // Start checking from 1 for the first number

        // Keep searching until a valid pair is found
        while (true) {
            // Check if the second number (n - first) has no zeros
            if (!contains_zero(n - first)) {
                break; // Found a valid pair -> stop
            } else {
                // Otherwise, increment 'first' until it has no zeros itself
                first++;
                while (contains_zero(first)) {
                    first++;
                }
            }
        }

        // Return the pair {first, n - first}
        return {first, n - first};
    }

private:
    // Utility function to check whether a number contains a digit '0'
    static constexpr bool contains_zero(int x) {
        if (x == 0) return true; // Special case: 0 itself "contains zero"
        while (x > 0) {
            if (x % 10 == 0) return true; // If the last digit is zero
            x /= 10;                       // Move to the next digit
        }
        return false; // No zero digits found
    }
};
