

int removeDuplicates(int* nums, int numsSize) {

    int *slow = nums ;// point to ther 1st element 



    for (int *fast = nums + 1 ; fast < nums + numsSize  ; fast ++ ){
        if ( *fast != *slow ){
            slow++ ;
            *slow = *fast ;
        }
    }
    return ( slow - nums ) + 1 ; 
}