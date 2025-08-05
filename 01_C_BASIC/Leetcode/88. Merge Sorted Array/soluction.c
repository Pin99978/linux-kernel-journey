void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    
    int p1 = m - 1  , p2 = n - 1;
    
    while ( p1 >= 0 && p2 >= 0 ){
        // from lest element to check
        if (nums1[p1] > nums2[p2]){
            nums1[p1 + p2 + 1] = nums1[p1];
            p1--;
        }else{
            nums1[p1 + p2 + 1] = nums2[p2];
            p2--;
        }
    }


    while (p2 >= 0){
        nums1[p1+p2+1] = nums2[p2];
        p2 --;
    }

}