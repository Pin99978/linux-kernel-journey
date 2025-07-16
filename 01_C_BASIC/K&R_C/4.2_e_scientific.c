#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]){
    double val , power;
    int i, sign , exp_sign = 1 , exponent = 0;
    for (i = 0; isspace(s[i]) ; i ++)
        ;
    sign = (s[i] == '-') ? -1 : 1; 
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0 ; isdigit(s[i]) ; i++)
        val = 10.0 * val + (s[i] - '0');
    
    if (s[i] == '.') 
        i++;
    
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E'){
        i++;
        if (s[i] == '-'){
            exp_sign = -1 ; 
            i++;
        }else if (s[i] =="+") {
            i++;
        }

        for (; isdigit(s[i]); i++)
            exponent = 10*exponent + (s[i] - '0');
        val = val * pow(10, exp_sign * exponent);
    }

    return sign * val / power;



}