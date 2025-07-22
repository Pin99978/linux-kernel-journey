char* toLowerCase(char* s) {
    
    for (int i = 0 ; s[i] != '\0' ; i++){
        // check the char i only in 65 - 122
        if ( (int)s[i] >= 65  && (int)s[i] <= 90 ){
            s[i] = s[i] + 32; // convert to ;pwer case
        }
    }   
    return s;
}