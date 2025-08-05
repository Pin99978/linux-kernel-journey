# 88. Merge Sorted Array

## Problem
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.


## 解題思路

### 反向雙指針法（從後往前填充）
1. 設置兩個指針 `p1` 和 `p2` 分別指向 `nums1` 和 `nums2` 的有效元素尾部
2. 從後往前比較兩個陣列的元素，將較大的元素放到 `nums1` 的尾部
3. 使用公式 `p1 + p2 + 1` 計算當前應該填充的位置
4. 如果 `nums2` 還有剩餘元素，繼續填入 `nums1`

### 為什麼從後往前？
- 避免覆蓋 `nums1` 中尚未處理的有效元素
- 利用 `nums1` 尾部的預留空間，實現原地合併

## 演算法步驟
1. 初始化指針：`p1 = m-1`, `p2 = n-1`
2. 當兩個指針都有效時，比較 `nums1[p1]` 和 `nums2[p2]`
3. 將較大者放到 `nums1[p1+p2+1]` 位置
4. 移動對應指針
5. 處理 `nums2` 的剩餘元素

## 複雜度分析
- **時間複雜度**: O(m + n) - 每個元素只處理一次
- **空間複雜度**: O(1) - 原地操作，不需額外空間

## C 語言實作

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1, p2 = n - 1;
    
    // 從後往前比較並填充
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p1 + p2 + 1] = nums1[p1];
            p1--;
        } else {
            nums1[p1 + p2 + 1] = nums2[p2];
            p2--;
        }
    }
    
    // 處理 nums2 的剩餘元素
    while (p2 >= 0) {
        nums1[p1 + p2 + 1] = nums2[p2];
        p2--;
    }
}
```

## 重要概念
- **two pointer**：使用兩個指針同時遍歷兩個陣列
- **inplace array**：在原始陣列上直接修改，節省空間


