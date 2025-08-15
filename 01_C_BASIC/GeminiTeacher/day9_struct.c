#include <stdio.h>

struct Car {
    char *make;
    char *model;
    int  year;
};


int main(){
    struct Car blend;
    struct Car *p_blend = &blend;
    blend.make = "Toyota";
    blend.model = "Camry";
    blend.year = 2008;
    printf("My car is  a %d %s %s\n" ,blend.year, blend.make  , blend.model);
        printf("My car is  a %d %s %s\n" ,p_blend->year, p_blend->make  , p_blend->model);
}