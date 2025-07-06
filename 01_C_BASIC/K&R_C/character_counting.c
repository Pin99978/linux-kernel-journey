#include <stdio.h>

//  count characters in input : 1st ver 


int main(){

//    long nc;
//nc
//    while (getchar() != EOF)
//        nc = nc + 1;
//    printf("%ld\n" , nc);


    double nc;
    for (nc = 0; getchar() != EOF; ++nc) 
        ;
    printf("%.0f\n" , nc);
}


