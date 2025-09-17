class Solution {
public:
    bool isPalindrome(string s) {
        // Get the length of the input string
        size_t n = s.size();

        // Two pointers: one starting from the left, one from the right
        int left = 0;
        int right = n - 1;

        // Continue until the two pointers meet
        while (left < right)
        {
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[left]))
            {
                left++;
                continue;
            }

            // Skip non-alphanumeric characters from the right
            if (!isalnum(s[right]))
            {
                right--;
                continue;
            }

            // Compare the lowercase version of the characters
            // If they don't match, it's not a palindrome
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            // Move both pointers inward
            left++;
            right--;
        }

        // If all valid characters matched, it's a palindrome
        return true;
    }
};
