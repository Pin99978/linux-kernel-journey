#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100

int getop(char []);
int getch(void);
void ungetch(int);
char buf[BUFSIZE];
int sp = 0; 
int bufp = 0;

double val[MAXVAL];
void push (double);
double pop(void);



int main(){
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s) != EOF)){
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop() , op2));
            else
                printf("error: zero divisor\n");
            break;
        default:
            break;
        }
    }
    return 0;
}

void push(double f)
{
    if (sp < MAXVAL){
        val[sp++] = f; 
    }
}

double pop(){
    if (sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}


int getop(char s[]){
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t' )
        ;
    s[1] = '\0';

    // deal with negative number
    if (c == '-'){
        if (isdigit(c = getch()) || c == '.'){
            s[1] = c;
            i = 1;
        }else{
            ungetch(c);
            return '-';
        }
    }else if (!isdigit(c) && c != '.'){
        return c;
    }else{
        i = 0;
    }

    if (c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar(); 
}