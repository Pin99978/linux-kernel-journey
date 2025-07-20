char findTheDifference(char* s, char* t) {
    char letter_s[26] = {0};
    char letter_t[26] = {0};

    int j = 0;

    for (int i = 0 ; s[i] != '\0' ; i++){
        char c = s[i];     
        int index = c - 'a';
        letter_s[index]++ ;  // convert char c into int and add the number in c
        }

    for (int i = 0 ; t[i] != '\0' ; i++){
        char c = t[i];   
        int index = c - 'a';
        letter_t[index]++ ; // convert char c into int and add the number in c

        }

    for (j = 0 ; j < 26 ; j++){
        if (letter_s[j] != letter_t[j]){
            return (char)(j + 'a') ;
        }
    }    
    return '\0';
}