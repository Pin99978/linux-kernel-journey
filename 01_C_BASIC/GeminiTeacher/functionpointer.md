
# C語言函式指標與呼叫堆疊解析

這份筆記分析了當一個函式（`calculator`）接受另一個函式（`add`）作為指標參數並呼叫它時，記憶體中呼叫堆疊 (Call Stack) 的詳細變化過程。

### 範例情境程式碼

```c
#include <stdio.h>

int add(int a, int b) {
    int sum = a + b;
    return sum;
}

void calculator(int a, int b, int (*op_ptr)(int, int)) {
    int result = op_ptr(a, b);
    printf("Result: %d\n", result);
}

int main(void) {
    // 我們將追蹤這一行的執行過程
    calculator(10, 5, add); 
    return 0;
}
```
記憶體堆疊追蹤 (Step-by-Step)
我們將追蹤當程式執行到 add 函式內部那一瞬間，堆疊從建立到達到最高點的過程。

1. 程式啟動：main 函式
程式執行時，作業系統會為 main 函式建立第一個堆疊幀 (Stack Frame)。這是在堆疊的最底部。
```
|---------------------|  <- 堆疊底部 (BOTTOM)
| Stack Frame: main   |
|---------------------|
| - 返回位址          |
|---------------------|
```
2. 呼叫 calculator 函式
main 函式呼叫 calculator，並傳入三個參數：10、5 和 add 函式的記憶體位址。此時，一個新的堆疊幀會被建立並疊加在 main 的上方。

這個屬於 calculator 的堆疊幀包含了：

參數 (Parameters): a, b 和 op_ptr。

區域變數 (Local Variables): result。

返回位址 (Return Address): 指向 main 函式中呼叫 calculator 之後的那一行指令。

關鍵點: op_ptr 這個變數的值，就是 add 函式在記憶體中的位址。
```
|--------------------------|  <- 堆疊頂部 (TOP)
| Stack Frame: calculator  |
|--------------------------|
| - int result             | (空間已準備好)
| - int (*op_ptr)          | (值: add 函式的位址)
| - int b                  | (值: 5)
| - int a                  | (值: 10)
| - 返回位址               | (指向 main)
|--------------------------|
| Stack Frame: main        |
|--------------------------|
| ...                      |
|--------------------------|  <- 堆疊底部 (BOTTOM)
```
3. 透過函式指標呼叫 add 函式
當 calculator 執行到 op_ptr(a, b) 時，程式會讀取 op_ptr 中的位址，並跳到 add 函式的程式碼去執行。此時，第三個堆疊幀，也就是 add 函式的堆疊幀，會被疊加到最頂端。

堆疊最高點的狀態
這是我們分析的最終時刻，呼叫堆疊長到了最高點。
```
|---------------------|  <- 堆疊頂部 (TOP)
| Stack Frame: add    |
|---------------------|
| - int sum           | (空間已準備好)
| - int b             | (值: 5)
| - int a             | (值: 10)
| - 返回位址          | (指向 calculator)
|---------------------|
| Stack Frame: calculator |
|---------------------|
| - int result        | (尚未賦值)
| - int (*op_ptr)     | (值: add 函式的位址)
| - int b             | (值: 5)
| - int a             | (值: 10)
| - 返回位址          | (指向 main)
|---------------------|
| Stack Frame: main   |
|---------------------|
| ...                 |
|---------------------|  <- 堆疊底部 (BOTTOM)
```
堆疊回縮 (The Stack Unwinds)
當函式執行完畢後，堆疊會依相反的順序被銷毀：

add 函式回傳 15。它的堆疊幀被從頂部彈出 (pop)。

控制權回到 calculator，result 變數被賦值為 15。calculator 執行完 printf 後結束，它的堆疊幀被彈出。

控制權回到 main，main 執行 return 0 後結束，它的堆疊幀被彈出。

堆疊變空，程式結束。