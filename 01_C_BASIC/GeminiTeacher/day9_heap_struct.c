#include <stdio.h>
#include <stdlib.h>

struct Car {
    char *blend;
    char *name;
    float  max_speed;
    int  year;      
};

int main(){
    struct Car *my_car = NULL;
    my_car =  (struct Car *)malloc(sizeof(struct Car));
    if(my_car == NULL) return 1;
    my_car -> blend = "BMW";
    my_car -> name = "X6";
    my_car -> year = 2024;
    my_car -> max_speed = 205.5;


    printf("the %s %s is producted in %d,and its maximum speed is %f", my_car -> blend , my_car->name , my_car->year , my_car -> max_speed );
    free(my_car);
    return 0;
}