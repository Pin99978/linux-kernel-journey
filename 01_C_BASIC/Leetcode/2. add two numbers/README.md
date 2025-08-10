# 2. Add Two Numbers (C)

- 實作檔：[`solution.c`](./solution.c)（函式：[`addTwoNumbers`](./solution.c)，型別：[`struct ListNode`](./solution.c)）

## 關鍵理解：`cur->next` 等於 `(*cur).next`，且一開始就是在寫 `dummy.next`
- `cur` 是指向節點的指標，初始化為 `cur = &dummy`。
- 運算子等價：`p->field` 與 `(*p).field` 完全相同。
- 當 `cur = &dummy` 時：
  - `cur->next` ≡ `(*cur).next` ≡ `dummy.next`
  - 也就是說，第一次配置的新節點其實是被接到 `dummy.next` 上，這也正是最後回傳的頭節點。
- 每次建立新節點後執行 `cur = cur->next`，`cur` 就會移到新串列的尾端，下一次的 `cur->next` 便會接在「目前尾節點」後面。

簡化流程：
1. 建立 `dummy` 節點並設 `cur = &dummy`，`dummy.next = NULL`。
2. 逐位相加（含進位 `carry`），每次用 `cur->next = malloc(...)` 接上新節點。
3. 寫入 `sum % 10`，再把 `cur` 往後移動到新節點。
4. 迴圈結束後若 `carry > 0`，再補一個節點。
5. 回傳 `dummy.next`。

## 重要程式片段
```c
// 初始化：此時 cur 指向 dummy，所以 cur->next 就是 dummy.next
struct ListNode dummy;
struct ListNode *cur = &dummy;
dummy.next = NULL;

// 每回合把新節點接在「目前尾端」；第一次其實就是寫 dummy.next
cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
cur->next->val = sum % 10;
cur->next->next = NULL;
cur = cur->next; // 尾端前進
```

## 複雜度
- 時間：O(max(m, n))
- 空間：O(max(m, n))（輸出鏈結串列所需）

## 常見易錯點
- 未將 `dummy.next` 初始化為 `NULL`。
- 遺漏 `#include <stdlib.h>` 導致 `malloc` 未宣告。
- 忘記最後的進位需要補一個節點。

## 參考
- 程式：[`Linux-Kernal/linux-kernel-journey/01_C_BASIC/Leetcode/2. add Two number/solution.c`](../../../../Linux-Kernal/linux-kernel-journey/01_C_BASIC/Leetcode/2.%20add%20Two%20number/solution.c)
- 函式：[`addTwoNumbers`](../../../../Linux-Kernal/linux-kernel-journey/01_C_BASIC/Leetcode/2.%20add%20Two%20number/solution.c)
- 型別：[`struct ListNode`](../../../../Linux-Kernal/linux-kernel-journey/01_C_BASIC/Leetcode/2.%20add%20Two%20number/solution.c)