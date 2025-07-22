# 203. Remove Linked List Elements

## 問題描述
Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that has `Node.val == val`, and return the new head.

**Example 1:**
- Input: head = [1,2,6,3,4,5,6], val = 6
- Output: [1,2,3,4,5]

**Example 2:**
- Input: head = [], val = 1
- Output: []

**Example 3:**
- Input: head = [7,7,7,7], val = 7
- Output: []

## solution

### Dummy Node 技巧

1. **創建虛擬頭節點**：避免單獨處理頭節點被刪除的情況
2. **two pointer遍歷**：
   - `cur`：iter original linked list all nodes
   - `ptr`：create the new linked list node


### 演算法步驟
1. inital the dummy node
```c
struct ListNode dummy;
struct ListNode *ptr = &dummy;  // ptr 指向 dummy 的地址
```
2. 遍歷原鏈表的每個節點
3. 如果節點值不等於目標值，將其加入結果鏈表
4. 移動到下一個節點
```c

// 連接節點
ptr -> next = cur;  // 將 cur 連接到新鏈表
ptr = ptr -> next;  // 移動 ptr 到新加入的節點
```
5. 確保結果鏈表正確終止（`ptr->next = NULL`）


## 複雜度分析
- **時間複雜度**：O(n)，其中 n 是鏈表的長度，需要遍歷整個鏈表
- **空間複雜度**：O(1)，只使用常數額外空間

