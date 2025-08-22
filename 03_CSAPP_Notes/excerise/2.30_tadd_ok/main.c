int tadd_ok(int x , int y){
    int pos_overflow , neg_overflow;
    int sum = x + y;
    pos_overflow =  x > 0 && y > 0 && sum < 0;
    neg_overflow =  x < 0 && y < 0 && sum > 0;
    return !pos_overflow && !neg_overflow;
}