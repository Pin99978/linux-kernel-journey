bool judgeCircle(char* moves) {
    
    int r = 0 , u = 0 ;
    int i = 0;
    for ( i = 0 ; i < strlen(moves) + 1 ; i++ ){
        switch(moves[i]){
            case 'R':
                r ++;
                break;
            case 'L':
                r --;
                break;
            case 'U':
                u ++;
                break;
            case 'D':
                u --;
                break;
            default:
        }
    }
    if ( r ==0 && u == 0) return true;
    else  return false;
}
