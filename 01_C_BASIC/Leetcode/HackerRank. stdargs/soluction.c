#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000

int  sum (int count,...) {
    va_list args;  // va_list datatype
    va_start(args , count);
    int total = 0;
    for (int i = 0 ; i < count ; i++){
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}

int min(int count,...) {
    va_list args;
    va_start(args,  count);
    int min_num = va_arg(args , int );
    
    // int from 1 because the upper has already read once
    for (int i = 1 ; i < count ; i++){
        int val = va_arg(args,int);
        if (val <= min_num){
            min_num = val; 
        }
    }
    va_end(args);
    return min_num;

}

int max(int count,...) {
    va_list args;
    va_start(args, count);
    int max_num = va_arg(args , int);
    for (int i = 1 ; i < count ; i++){
        int val = va_arg(args , int );
        if ( val >= max_num){
            max_num = val;
        }
    }
    va_end(args);
    return max_num;
}

int test_implementations_by_sending_three_elements() {
    srand(time(NULL));
    
    int elements[3];
    
    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    
    fprintf(stderr, "Sending following three elements:\n");
    for (int i = 0; i < 3; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }
    
    int elements_sum = sum(3, elements[0], elements[1], elements[2]);
    int minimum_element = min(3, elements[0], elements[1], elements[2]);
    int maximum_element = max(3, elements[0], elements[1], elements[2]);

    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
    
    int expected_elements_sum = 0;
    for (int i = 0; i < 3; i++) {
        if (elements[i] < minimum_element) {
            return 0;
        }
        
        if (elements[i] > maximum_element) {
            return 0;
        }
        
        expected_elements_sum += elements[i];
    }
    
    return elements_sum == expected_elements_sum;
}
