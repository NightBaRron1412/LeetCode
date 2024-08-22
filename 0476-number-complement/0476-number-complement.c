int findComplement(int num) {
    int num1 = num;
    unsigned op = 0b1;
    while (num1 != 1){
        num1 = num1 >> 1;
        op = op << 1;
        op = op + 0b1;
    }
    return ~num & op;
}



