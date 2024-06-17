#include <math.h>
bool judgeSquareSum(int c) {
if (c == 0){
    return true;
}
    for(long int a = 1; a <= sqrt(c); a++){
       double b = sqrt(c - a * a);  // Compute `b` as the square root of `c - a^2`
            if (b == (int)b) {                 // Check if `b` is an integer
                return true;                   // If `b` is an integer, return true
            }
        }

    return false;
}