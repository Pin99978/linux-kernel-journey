# 232. Implement Queue using Stacks

## 問題描述
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).

**實作函數：**
- `void push(int x)` - Pushes element x to the back of the queue
- `int pop()` - Removes the element from the front of the queue and returns it
- `int peek()` - Returns the element at the front of the queue
- `boolean empty()` - Returns true if the queue is empty, false otherwise

**注意事項：**
- 只能使用標準的堆疊操作（push to top, peek/pop from top, size, is empty）
- 您的實作應該支援所有常見的佇列操作

## 解題思路

### 雙堆疊設計 (Two Stack Design)
使用兩個 two Stacks 來模擬佇列的 FIFO 特性：
- **inStack**: 負責接收新元素 (push 操作)
- **outStack**: 負責輸出元素 (pop/peek 操作)

### 核心概念
Queue 是 FIFO (First In First Out)，而 Stack 是 LIFO (Last In First Out)。通過 two Stacks 的組合，可以實現：
```
輸入順序: 1 → 2 → 3
inStack:  [1, 2, 3] (top = 3)
轉移到outStack: [3, 2, 1] (top = 1)
輸出順序: 1 → 2 → 3 (符合 FIFO)
```

## C 語言實作詳解

### 資料結構設計
```c
typedef struct {
    int inStack[STACK_SIZE];    // 輸入 Stack
    int intop;                  // 輸入 instock index
    int outStack[STACK_SIZE];   // 輸出 Stack  
    int outop;                  // 輸出 outStack index
} MyQueue;
```

**設計要點：**
- 使用陣列實作堆疊，避免動態記憶體分配的複雜性
- `top = -1` 表示空堆疊
- `STACK_SIZE = 100` 定義最大容量

### 關鍵操作實作

#### 1. Push 操作
```c
void myQueuePush(MyQueue* obj, int x) {
    if (obj -> intop < STACK_SIZE -1){
        obj -> inStack[++(obj->intop)] = x;
    }
}
```
- 所有新元素都推入 `inStack`
- 前置遞增：`++intop` 先增加索引再存值

#### 2. Pop/Peek 操作的懶惰轉移 (Lazy Transfer)
```c
// 轉移邏輯（pop 和 peek 共用）
if (obj -> outop == -1){
    while (obj -> intop != -1){
       obj->outStack[++(obj->outop)] = obj->inStack[(obj->intop)--];
    }
}
```

**關鍵策略：**
- 只有當 `outStack` 為空時才進行轉移
- 一次性將 `inStack` 的所有元素轉移到 `outStack`
- 轉移後元素順序正好符合 FIFO 要求

#### 3. Pop 操作
```c
int myQueuePop(MyQueue* obj) {
    // ...轉移邏輯...
    return obj -> outStack[ (obj->outop)--];
}
```

#### 4. Peek 操作
```c
int myQueuePeek(MyQueue* obj) {
    // ...轉移邏輯...
    return obj ->outStack[ obj->outop] ;
}
```

#### 5. Empty 檢查
```c
bool myQueueEmpty(MyQueue* obj) {
    return obj->intop == -1 && obj->outop == -1;
}
```

## 演算法分析

### 時間複雜度
- **Push**: O(1) - 直接推入 inStack
- **Pop**:  O(1) - 雖然單次轉移需要 O(n)，但每個元素最多被轉移一次
- **Peek**: O(1) - 同 Pop 邏輯
- **Empty**:O(1) - 簡單條件檢查

### 空間複雜度
- O(n) - 需要兩個堆疊來存儲最多 n 個元素

## 工作流程範例

```
初始狀態: inStack=[], outStack=[]

push(1): inStack=[1], outStack=[]
push(2): inStack=[1,2], outStack=[]
peek():  轉移後 inStack=[], outStack=[2,1], 返回 1
pop():   inStack=[], outStack=[2], 返回 1
push(3): inStack=[3], outStack=[2]
pop():   inStack=[3], outStack=[], 返回 2
```

## 重要實作細節

### 1. 索引管理
```c
// 正確的堆疊操作
push: arr[++top] = value;  // 先遞增再賦值
pop:  return arr[top--];   // 先返回再遞減
peek: return arr[top];     // 只讀取不修改
```

### 2. 邊界檢查
- Push 前檢查是否超出 `STACK_SIZE`
- Pop/Peek 前確保有元素可操作（通過轉移保證）

### 3. 記憶體管理
```c
MyQueue* myQueueCreate() {
    MyQueue *queue = malloc(sizeof(MyQueue)); 
    queue -> intop = -1 , queue -> outop = -1;
    return queue;
}

void myQueueFree(MyQueue* obj) {
    free(obj);  // 需要實作記憶體釋放
}
```

