class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2 != 0)
        {
            return false;
        }

        int minOpen {0};
        int maxOpen {0};

        for (int i = 0; i < s.length(); ++i)
        {
            if (locked[i] == '1')
            {
                if (s[i] == '(')
                {
                    minOpen++;
                    maxOpen++;
                }
                else
                {
                    minOpen--;
                    maxOpen--;
                }
            }
            else
            {
                minOpen--;
                maxOpen++;
            }

            if (maxOpen < 0)
            {
                return false;
            }
            minOpen = max(minOpen, 0);
        }

        int minClose {0};
        int maxClose {0};
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (locked[i] == '1')
            {
                if (s[i] == ')')
                {
                    minClose++;
                    maxClose++;
                }
                else
                {
                    minClose--;
                    maxClose--;
                }
            }
            else
            {
                minClose--;
                maxClose++;
            }

            if (maxClose < 0)
            {
                return false;
            }
            minClose = max(minClose, 0);
        }

        return minOpen == 0 && minClose == 0;
    }
};