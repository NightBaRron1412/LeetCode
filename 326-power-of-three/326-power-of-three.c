bool isPowerOfThree(int n){
    double temp = n;
    while (temp >= 3){
    temp /= 3;
    }
    if (temp == 1){
    return true;
    }
    else{
    return false;
    }
}