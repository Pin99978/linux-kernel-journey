# 448. Find All Numbers Disappeared in an Array

## 問題描述
Given an array `nums` of `n` integers where `nums[i]` is in the range `[1, n]`, return an array of all the integers in the range `[1, n]` that do not appear in `nums`.

**Example 1:**
```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
```

**Example 2:**
```
Input: nums = [1,1]
Output: [2]
```

**Constraints:**
- `n == nums.length`
- `1 <= n <= 10^5`
- `1 <= nums[i] <= n`

## 解題思路

### 方法一：頻率計數法 (當前實作)
使用額外的陣列來記錄每個數字的出現次數：
1. 創建大小為 `numsSize + 1` 的計數陣列
2. 遍歷原陣列，統計每個數字出現次數
3. 遍歷範圍 `[1, n]`，找出計數為 0 的數字

### 演算法步驟
1. 動態分配記憶體給結果陣列和計數陣列
2. 統計每個數字的出現頻率
3. 找出缺失的數字並存入結果陣列
4. 設定返回陣列大小並返回結果

## C 語言實作

### 方法一：頻率計數法
```c
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *missing = malloc(sizeof(int) * numsSize);
    int *arr = calloc(numsSize + 1, sizeof(int));

    // 統計每個數字出現次數
    for (int i = 0; i < numsSize; i++) {
        arr[nums[i]]++;
    }
    
    // 找出缺失的數字
    int j = 0;
    for (int i = 1; i <= numsSize; i++) {
        if (arr[i] == 0) {
            missing[j] = i;
            j++;
        }
    }
    
    *returnSize = j;
    free(arr);  // 釋放臨時陣列記憶體
    return missing;
}
```

### 方法二：原地標記法（優化解法）
**空間複雜度 O(1) 的解法**

```c
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    // 第一次遍歷：將出現的數字對應索引位置標記為負數
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;  // 轉換為 0-based 索引
        if (nums[index] > 0) {
            nums[index] = -nums[index];  // 標記為負數
        }
    }
    
    // 分配結果陣列
    int *result = malloc(sizeof(int) * numsSize);
    int j = 0;
    
    // 第二次遍歷：正數位置對應的數字即為缺失數字
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[j++] = i + 1;  // 轉換回 1-based
        }
    }
    
    // 恢復原陣列（可選）
    for (int i = 0; i < numsSize; i++) {
        nums[i] = abs(nums[i]);
    }
    
    *returnSize = j;
    return result;
}
```

## 複雜度分析

### 方法一：頻率計數法
- **時間複雜度**：O(n)，需要兩次遍歷
- **空間複雜度**：O(n)，使用額外的計數陣列

### 方法二：原地標記法
- **時間複雜度**：O(n)，需要兩次遍歷
- **空間複雜度**：O(1)，不使用額外空間（除了結果陣列）

