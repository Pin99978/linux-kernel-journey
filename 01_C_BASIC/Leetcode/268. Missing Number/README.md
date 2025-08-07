# 268. Missing Number

## 問題描述
Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

**Example 1:**
- Input: nums = [3,0,1]
- Output: 2
- Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

**Example 2:**
- Input: nums = [0,1]
- Output: 2
- Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

**Example 3:**
- Input: nums = [9,6,4,2,3,5,7,0,1]
- Output: 8
- Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

## 解題思路

### 哈希表計數法 (Hash Table Counting)
使用額外的陣列來標記每個數字的出現次數：
1. 創建大小為 `numsSize + 1` 的陣列作為哈希表
2. 遍歷原陣列，在哈希表中標記每個數字的出現
3. 再次遍歷哈希表，找到計數為 0 的索引即為缺失數字

### 演算法步驟
1. 使用 `calloc()` 分配 `numsSize + 1` 大小的陣列，初始值為 0
2. 第一次遍歷：`arr[nums[i]]++` 標記每個數字的出現
3. 第二次遍歷：找到 `arr[i] == 0` 的索引 `i`
4. 返回缺失的數字

## C 語言實作

```c
int missingNumber(int* nums, int numsSize) {
    // 使用 calloc 創建哈希表，初始值為 0
    int *arr = calloc(numsSize + 1, sizeof(int));
    int i;
    int missing;
    
    // 第一次遍歷：標記每個數字的出現
    for (i = 0; i < numsSize; i++) {
        arr[nums[i]]++;
    }
    
    // 第二次遍歷：找到計數為 0 的索引
    for (i = 0; i <= numsSize; i++) {
        if (arr[i] == 0) {
            missing = i;
        }
    }
    
    return missing;
}
```

## 複雜度分析
- **時間複雜度**：O(n)，需要兩次遍歷
- **空間複雜度**：O(n)，使用額外的哈希表陣列

## 重要概念

### calloc() vs malloc()
```c
// calloc() 自動初始化為 0
int *arr = calloc(numsSize + 1, sizeof(int));

// malloc() 需要手動初始化
int *arr = malloc((numsSize + 1) * sizeof(int));
memset(arr, 0, (numsSize + 1) * sizeof(int));
```

### 哈希表標記技巧
- 使用陣列索引作為鍵，陣列值作為計數器
- 適用於數值範圍較小且連續的情況

## 優化解法提示

### 位元運算解法 (XOR)
```c
int missingNumber(int* nums, int numsSize) {
    int missing = numsSize;
    for (int i = 0; i < numsSize; i++) {
        missing ^= i ^ nums[i];
    }
    return missing;
}
```
- **時間複雜度**：O(n)
- **空間複雜度**：O(1)

為什麼想到 XOR？
問題：在 [0, n] 範圍內找缺失的一個數字
關鍵洞察：除了缺失的數字，其他都出現了兩次！

原始視角：nums = [3,0,1]，缺失 2
XOR 視角：[0,1,2,3] vs [3,0,1]
        ↓
如果我們把兩個陣列合併：[0,1,2,3,3,0,1]
除了缺失的 2，其他數字都出現 2 次！

// 合併後的陣列 XOR
0 ^ 1 ^ 2 ^ 3 ^ 3 ^ 0 ^ 1
= (0^0) ^ (1^1) ^ 2 ^ (3^3)  // 相同數字互相抵消
= 0 ^ 0 ^ 2 ^ 0
= 2  // 只剩下缺失的數字！


XOR 經典應用場景：
1. 找出現奇數次的數字
2. 交換變數不用額外空間
3. 找兩個陣列的差異
4. 檢測資料完整性