class Solution {
public:
    int minimizeXor(int num1, int num2) {
        #define GET_BIT(value, bit) (((value) >> (bit)) & 1)
        #define SET_BIT(value, bit) ((value) |= (1 << (bit)))
        #define UNSET_BIT(value, bit) ((value) &= ~(1 << (bit)))

        int res = num1;
        int target_bits_count = __builtin_popcount(num2);
        int set_bits_count = __builtin_popcount(num1);

        if (set_bits_count > target_bits_count) {
            for (int i = 0; i < 32 && set_bits_count > target_bits_count; ++i) {
                if (GET_BIT(res, i)) {
                    UNSET_BIT(res, i);
                    --set_bits_count;
                }
            }
        } else if (set_bits_count < target_bits_count) {
            for (int i = 0; i < 32 && set_bits_count < target_bits_count; ++i) {
                if (!GET_BIT(res, i)) {
                    SET_BIT(res, i);
                    ++set_bits_count;
                }
            }
        }

        return res;
    }
};
