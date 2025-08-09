# 422. FizzBuzz (C)

- 實作檔：[`solution.c`](./solution.c)

## 問題描述
給定整數 n，回傳長度為 n 的字串陣列：
- i 同時被 3 與 5 整除 → "FizzBuzz"
- 僅被 3 整除 → "Fizz"
- 僅被 5 整除 → "Buzz"
- 否則為數字字串

## 解題思路
- 配置一個字串指標陣列 `char **arr = malloc(n * sizeof(char *))`。
- 迴圈 1..n 依規則產生字串：
  - "Fizz"/"Buzz"/"FizzBuzz" 直接用常值字串長度配置。
  - 其它數字以 `sprintf` 寫入暫存 `snum`，再依長度配置並複製。
- 以輸出參數 `*returnSize = n` 回傳結果長度。
- 回傳 `arr`。

時間複雜度：O(n)  
空間複雜度：O(n)（加上所有輸出字串總長度）

## 指標重點（Pointer to Pointer）
- `char **arr` 為「指向字元指標的指標」，可視為「字串指標的陣列」：
  - `arr[i]` 是 `char *`，各自指向獨立配置於 heap 的字串。
- `int *returnSize` 為輸出參數（out param），在函式內寫入結果大小：`*returnSize = n;`。

