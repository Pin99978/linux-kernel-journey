/*
    Compile and run sample code that uses show_bytes(file show-bytes.c) on different machines to which you have access. Determine the byte orderings used by these machines
*/ 

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    int i = 0;
    for (i = 0 ; i < len ; i++){
        printf("%.2x " , start[i]);
    }
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer) &x , sizeof(int));
}


void show_float(float x){    
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
    show_bytes((byte_pointer) &x , sizeof(void *));
}

void show_short(short x){
    show_bytes((byte_pointer)&x , sizeof(short));
}

void show_long(long x){
    show_bytes((byte_pointer)&x , sizeof(long));
}

void show_double(long x){
    show_bytes((byte_pointer)&x , sizeof(double));
}


void test_value(int val){
    int ival = val;
    float ifloat = (float) ival;
    void *iptr = &ival;
    short ishort = (short) ival;
    long ilong = (long) ival;
    double idoulbe = (double) ival;


    show_int(ival);
    show_float(ifloat);
    show_pointer(iptr);
    show_short(ishort);
    show_long(ilong);
    show_double(idoulbe);
}


int main(){
    int x = 10;
    test_value(x);
}