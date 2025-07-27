# 61. Rotate List

## 問題描述
Given the head of a linked list, rotate the list to the right by k places.

**Example 1:**
```
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```

**Example 2:**
```
Input: head = [0,1,2], k = 4
Output: [2,0,1]
```

## 解題思路

### 
1. **計算串列長度**：遍歷一次獲得總長度 n
2. **處理 k 值**：k = k % n（避免不必要的旋轉）
3. **找到新的尾節點**：位置在 n - k - 1
4. **重新連接**：斷開舊連接，建立新連接


## 重要概念
in C , pointer的應用以及模擬在記憶體memory的操作。

### 邊界處理
- k = 0 或 k = n 的倍數時不需旋轉
- 空串列或單節點串列的處理

## 複雜度分析
- **時間複雜度**：O(n)，需要遍歷串列兩次
- **空間複雜度**：O(1)，只使用常數額外空間


