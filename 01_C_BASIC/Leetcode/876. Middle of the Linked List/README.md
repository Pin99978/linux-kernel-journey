# 876. Middle of the Linked List

## 問題描述
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

## 解題思路

### 快慢指標技巧 (Two Pointers - Fast & Slow)
使用快慢指標遍歷鏈結串列：
- **快指標 (fast)**：每次移動兩步
- **慢指標 (slow)**：每次移動一步
- 當快指標到達終點時，慢指標正好位於中點

### 演算法原理
1. 初始化兩個指標都指向 head
2. 快指標每次移動 2 步，慢指標每次移動 1 步
3. 當快指標無法再移動時，慢指標就在中點位置

### 視覺化範例
```
奇數長度串列: [1] -> [2] -> [3] -> [4] -> [5]
初始:        f,s
步驟1:            s      f
步驟2:                 s           f (結束)
結果: 慢指標指向節點 3

偶數長度串列: [1] -> [2] -> [3] -> [4]
初始:        f,s
步驟1:            s      f
步驟2:                 s      f (結束)
結果: 慢指標指向節點 3 (第二個中點)
```

### C 語言實作要點
```c
// 終止條件檢查兩個情況：
while (fast != NULL && fast->next != NULL) {
    // fast != NULL: 避免奇數長度時越界
    // fast->next != NULL: 避免偶數長度時越界
}
```

## 複雜度分析
- **時間複雜度**：O(n) - 遍歷鏈結串列一次
- **空間複雜度**：O(1) - 只使用常數額外空間

## 重要概念
- **快慢指標**：經典的鏈結串列遍歷技巧
- **邊界處理**：正確處理奇數/偶數長度串列
- **指標操作**：安全的指標移動與NULL檢查