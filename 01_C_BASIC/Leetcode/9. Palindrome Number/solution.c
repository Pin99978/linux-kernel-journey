bool isPalindrome(int x) {
    
    if (x < 0) return false;

    int remainder;
    double reverse = 0 ; // because int overflow in this code 
    int temp = x;

    while (x > 0){
        remainder = x % 10;
        reverse = reverse * 10 + remainder;
        x = x / 10;
    }
    if (reverse == temp)
        return true;
    else
        return false;
}