# 1920. Build Array from Permutation

## 問題描述
給定一個 **0-indexed** 的整數陣列 `nums`（陣列長度為 `n`），你需要建立一個相同長度的陣列 `ans`，其中 `ans[i] = nums[nums[i]]`。

回傳建立的陣列 `ans`。

### 範例
```
輸入: nums = [0,2,1,5,3,4]
輸出: [0,1,2,4,5,3]
解釋: 
ans[0] = nums[nums[0]] = nums[0] = 0
ans[1] = nums[nums[1]] = nums[2] = 1
ans[2] = nums[nums[2]] = nums[1] = 2
ans[3] = nums[nums[3]] = nums[5] = 4
ans[4] = nums[nums[4]] = nums[3] = 5
ans[5] = nums[nums[5]] = nums[4] = 3
```

## 解題思路

### 直接映射法 (Direct Mapping)
這是一個簡單的陣列操作問題，核心概念是理解 **索引的二次查找**：
1. 對於每個位置 `i`，我們需要找到 `nums[i]` 作為新的索引
2. 然後使用這個新索引去取得 `nums[nums[i]]` 的值
3. 將結果存入新陣列的對應位置

### 演算法步驟
1. 動態分配記憶體給結果陣列
2. 遍歷原陣列，對每個元素進行二次查找
3. 設定返回陣列大小
4. 返回結果陣列

## C 語言實作重點

### 動態記憶體分配 (malloc)
```c
int *arr = malloc(numsSize * sizeof(int));
```

**關鍵概念：**
- `malloc()` 在 **heap** 上分配記憶體空間
- 分配大小：`numsSize * sizeof(int)` 確保有足夠空間存放 `numsSize` 個整數
- 返回 `void*` 指標，需要轉型為 `int*`

### 記憶體分配失敗處理
```c
if (!arr) return NULL;
```

**最佳實務：**
- 總是檢查 `malloc()` 是否成功
- 失敗時返回 `NULL` 避免程式崩潰
- 在生產環境中應加入錯誤日誌

### 返回陣列大小設定
```c
*returnSize = numsSize;
```

**指標解引用：**
- `returnSize` 是指向整數的指標
- 使用 `*returnSize` 設定呼叫者的變數值
- LeetCode 慣例：透過指標參數回傳陣列大小

## 記憶體管理概念

### Stack vs Heap
- **Stack（堆疊）**: 區域變數，自動管理，函式結束後自動釋放
- **Heap（堆積）**: 動態分配，需手動管理，使用 `malloc()`/`free()`

### malloc() 的重要性
```c
// ❌ 錯誤：返回區域變數位址
int result[1000];  // stack 上的陣列
return result;     // 危險！函式結束後記憶體被釋放

// ✅ 正確：動態分配
int *result = malloc(size * sizeof(int));  // heap 上分配
return result;     // 安全，記憶體持續有效
```