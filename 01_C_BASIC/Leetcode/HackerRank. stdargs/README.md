# HackerRank: stdargs（C 可變參數）

- 實作檔：[`soluction.c`](./soluction.c)
- 目標：以 C 標頭 `<stdarg.h>` 實作可變參數函式 `sum`、`min`、`max`。

## 核心觀念：<stdarg.h>
C 以「固定參數 + 省略號 ...」定義可變參數函式，例如：
```c
int sum(int count, ...);
```
使用步驟：
1. 宣告清單：`va_list args;`
2. 初始化：`va_start(args, last_fixed_param);`（第二參數要填「最後一個固定參數」的名字）
3. 逐一取值：`T x = va_arg(args, T);`（T 是實際放入的型別）
4. 結束：`va_end(args);`

注意：
- 預設提升（default argument promotions）：`char/short -> int`、`float -> double`。取值型別需與呼叫端實際型別一致，否則為未定義行為。
- 可變參數沒有型別資訊與數量資訊，必須用額外參數（如本題的 `count`）來控制讀取次數。
- 若要轉傳參數到另一個 `va_list`，使用 `va_copy(dst, src)`。

## 本專案的三個函式
- `int sum(int count, ...)`：累加 `count` 個整數。
- `int min(int count, ...)`：取 `count` 個整數的最小值。
- `int max(int count, ...)`：取 `count` 個整數的最大值。

`sum` 的寫法正確地讀取了 `count` 次：
```c
va_list args;
va_start(args, count);
for (int i = 0; i < count; i++) {
    total += va_arg(args, int);
}
va_end(args);
```

### 常見陷阱與修正（min/max）
目前 `min`/`max` 在先讀一個值後，又迴圈跑 `count` 次各再讀一個值，總共讀了 `count + 1` 個參數，會造成未定義行為。正確做法是：
- 先讀第一個值作為初值
- 再讀「剩下的 `count - 1` 個」值

建議修正如下：

```c
int min(int count, ...) {
    va_list args;
    va_start(args, count);

    // 預設至少一個參數；若需防呆可加上 if (count <= 0) {...}
    int min_num = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        if (val < min_num) {
            min_num = val;
        }
    }

    va_end(args);
    return min_num;
}

int max(int count, ...) {
    va_list args;
    va_start(args, count);

    int max_num = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        if (val > max_num) {
            max_num = val;
        }
    }

    va_end(args);
    return max_num;
}
```

## 使用前提與邊界條件
- 呼叫端必須保證 `count >= 1`（尤其對 `min`/`max`），且實際傳入的引數數量與 `count` 一致。
- 所有引數型別需與 `va_arg` 取得的型別一致（此處皆為 `int`）。

## 範例
```c
sum(3, 10, 20, 30);        // 60
min(3, 5, 2, 9);           // 2
max(3, 5, 2, 9);           // 9
```

## 編譯（Windows, MinGW）
```bash
gcc -std=c11 -Wall -Wextra -O2