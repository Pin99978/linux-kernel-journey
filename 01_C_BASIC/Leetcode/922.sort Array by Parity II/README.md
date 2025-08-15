# 922. Sort Array by Parity II

## 問題描述
Given an array of integers `nums`, half of the integers in `nums` are odd, and the other half are even.

Sort the array so that whenever `nums[i]` is odd, `i` is odd, and whenever `nums[i]` is even, `i` is even.

Return any answer array that satisfies this condition.

**Example 1:**
```
Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
```

**Example 2:**
```
Input: nums = [2,3]
Output: [2,3]
```

## 解題思路

### 分離重組法 (Separate and Recombine)
這個解法使用了三個步驟來解決問題：
1. **分離階段**：將原陣列中的偶數和奇數分別存放到兩個臨時陣列
2. **重組階段**：根據索引的奇偶性，從對應的臨時陣列中取值
3. **返回結果**：返回重新組織後的陣列

### 演算法步驟
1. 建立結果陣列 `arr` 和兩個臨時陣列 `arr_even`、`arr_odd`
2. 第一次遍歷：將偶數放入 `arr_even`，奇數放入 `arr_odd`
3. 第二次遍歷：
   - 如果當前索引 `i` 是偶數，從 `arr_even` 取值
   - 如果當前索引 `i` 是奇數，從 `arr_odd` 取值

### C 語言實作

```c
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    // 動態分配結果陣列
    int *arr = malloc(numsSize * sizeof(int));
    
    // 建立偶數和奇數的臨時陣列
    int arr_even[numsSize / 2];
    int arr_odd[numsSize / 2];
    int i = 0, j = 0, k = 0;
    
    // 第一次遍歷：分離偶數和奇數
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            arr_even[j] = nums[i];
            j++;
        } else {
            arr_odd[k] = nums[i];
            k++; 
        }
    }
    
    // 第二次遍歷：根據索引奇偶性重組
    int odd = 0, even = 0;
    for (i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            arr[i] = arr_even[even];
            even++;
        } else {
            arr[i] = arr_odd[odd];
            odd++;
        }
    }
    
        git commit -m "feat: add LeetCode 922 Sort Array by Parity II C solution with documentation"
    return arr;
}
```

## 複雜度分析
- **時間複雜度**：O(n)，需要遍歷陣列兩次
- **空間複雜度**：O(n)，需要額外的空間來存放臨時陣列和結果陣列

## 重要概念
- **陣列分離與重組**：將問題分解為更簡單的子問題
- **索引奇偶性判斷**：使用 `i % 2` 來判斷索引的奇偶性
- **動態記憶體分配**：使用 `malloc()` 分配返回陣列的記憶體
- **兩指針技巧**：可用於優化空間複雜度

## 記憶體管理
- 確保使用 `malloc()` 分配足夠的記憶體空間
- 正確設置 `*returnSize` 的值
- 呼叫者負責使用 `free()` 釋放記憶體

