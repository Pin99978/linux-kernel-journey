#include <stdlib.h>


int main(void){
    int *my_block = (int *)malloc(100 * sizeof(int));

    free(my_block);

    return 0 ;
}