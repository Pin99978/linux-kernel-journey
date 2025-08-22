

int tsub_ok(int x , int y){
    return tadd_ok(x, -y);
}

int tadd_ok(int x , int y){
    int pos_overflow , neg_overflow;
    int sum = x + y;
    pos_overflow =  x > 0 && y > 0 && sum < 0;
    neg_overflow =  x < 0 && y < 0 && sum > 0;
    return !pos_overflow && !neg_overflow;
}

// if 4-bit again
// x = -7 y = -7

return tadd(-7 , 7) // should overflow

sum = 0
pos_overflow 

