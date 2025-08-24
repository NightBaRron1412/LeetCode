class Solution {
public:
    bool isPalindrome(string s) {

        // Get the length of the input string
        size_t n = s.size();

        // Two pointers: one starting from the left, one from the right
        int p1 = 0;
        int p2 = n - 1;

        // Loop until the two pointers meet in the middle
        while (p1 < p2)
        {
            // Move the left pointer forward until it points to an alphanumeric character
            while (p1 < p2 && !isalnum((unsigned char)s[p1]))
            {
                p1++;
            }

            // Move the right pointer backward until it points to an alphanumeric character
            while (p1 < p2 && !isalnum((unsigned char)s[p2]))
            {
                p2--;
            }

            // Compare the two characters (case-insensitive).
            // If they don't match, the string is not a palindrome
            if (tolower((unsigned char)s[p1]) != tolower((unsigned char)s[p2]))
            {
                return false;
            }

            // If they match, move both pointers closer to the center
            p1++;
            p2--;
        }

        // If all pairs matched, the string is a palindrome
        return true;
    }
};
