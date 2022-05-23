

int romanToInt(char * s){
    int res = 0; /* Initializing a variable to store the result */

    for (char i = 0; s[i] != 0; i++) /* iterating through the string */
    {

        /*---------------------- If the character is "I" ---------------------------*/
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V') /* Checking if the next character is "V" */
            {
                res += 4; /* add 4 to the result */
                i++;      /* Skipping the next character (V) */
                continue; /* Checking for next character */
            }
            else if (s[i + 1] == 'X') /* Checking if the next character is "X" */
            {
                res += 9; /* add 9 to the result */
                i++;      /* Skipping the first character (X) */
                continue; /* Checking for next character */
            }
            else
            {
                res++; /* Adding I value to the result "1" */
            }
        }

        /*---------------------- If the character is "V" ---------------------------*/
        if (s[i] == 'V')
        {
            res += 5; /* Adding V value to the result "5" */
        }

        /*---------------------- If the character is "X" ---------------------------*/
        if (s[i] == 'X')
        {
            if (s[i + 1] == 'L') /* Checking if the next character is "L" */
            {
                res += 40; /* add 40 to the result */
                i++;       /* Skipping the next character (L) */
                continue;  /* Checking for next character */
            }
            else if (s[i + 1] == 'C') /* Checking if the next character is "C" */
            {
                res += 90; /* add 90 to the result */
                i++;       /* Skipping the next character (C) */
                continue;  /* Checking for next character */
            }
            else
            {
                res += 10; /* Adding X value to the result "10" */
            }
        }

        /*---------------------- If the character is "L" ---------------------------*/
        if (s[i] == 'L')
        {
            res += 50; /* Adding L value to the result "50" */
        }

        /*---------------------- If the character is "C" ---------------------------*/
        if (s[i] == 'C')
        {
            if (s[i + 1] == 'D') /* Checking if the next character is "D" */
            {
                res += 400; /* add 400 to the result */
                i++;        /* Skipping the next character (D) */
                continue;   /* Checking for next character */
            }
            else if (s[i + 1] == 'M') /* Checking if the next character is "M" */
            {
                res += 900; /* add 900 to the result */
                i++;        /* Skipping the next character (M) */
                continue;   /* Checking for next character */
            }
            else
            {
                res += 100; /* Adding C value to the result "100" */
            }
        }

        /*---------------------- If the character is "D" ---------------------------*/
        if (s[i] == 'D')
        {
            res += 500; /* Adding D value to the result "500" */
        }

        /*---------------------- If the character is "M" ---------------------------*/
        if (s[i] == 'M')
        {
            res += 1000; /* Adding M value to the result "1000" */
        }
    }

return res;
}