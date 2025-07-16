/*Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
 occurrence of t in s, or -1 if there is none.  */

// problem description
// char s[] = "look for the needle in the haystack";
// char t[] = "the";

//return the rightmost -> 22

/*Pseudocode 
1. declare i , j , occur = -1 
2. loop the s , and if s[i] == t[j]
let occur = i
3. loop t[j] , each loop need to i++
   for (j = 0 ; t[j] == s[i++] && t[j] != "\0", j++){
        ;
   }
   // means t[j] isn't match
   if t[j] != '\0';
       occur = -1 ;  initial occur

   return occur

*/

#include <stdio.h>


int strindex(char s[], char t[]);

int main(){
    int occur;

    char s[] = "look for the needle in the haystack";
    char t[] = "the";
    occur = strindex(s , t);
    printf("the string t is happen at the position %d of s\n" , occur);


    return 0;
}

int strindex(char s[] , char t[]){
    int i , j , k, occur = -1;

    for (i = 0; s[i] != '\0'; i++){
        for (j = i , k = 0 ; t[k] != '\0' && s[j] == t[k] ; j++ , k++ ){
            ;
        }
        if (t[k] == '\0'){
            occur = i;
        }

    }
    return occur;
}

