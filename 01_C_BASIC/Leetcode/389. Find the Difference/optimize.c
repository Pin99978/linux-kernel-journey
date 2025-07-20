char findTheDifference(char* s, char* t) {
        char result = 0;

        for (int i = 0 ; s[i] != '\0' ; i++){
            result ^= s[i];
        }

        for (int i = 0 ; t[i] != '\0' ; i++){
            result ^= t[i];
        }      

        return result;
}