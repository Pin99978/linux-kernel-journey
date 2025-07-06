#include <stdio.h>

int fahrtocel(int fahr);

int main(){

    int input , output;
    int lower , upper , step;
    
    lower = 0 ;
    upper = 300;
    step  = 20;

    while (input <= upper){
        output =  fahrtocel(input);
        input = input + step;
    }

    return 0;
}

int fahrtocel( int fahr ) {
   int celsius;
   celsius = 5 * ( fahr -32 ) /9;
   return celsius;

}
