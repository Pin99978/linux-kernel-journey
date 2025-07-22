# 231. Power of Two

## 問題描述
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

## 解題思路

### 位運算優化解法 (Bit Manipulation)
利用位元運算的特性來判斷 2 的冪次方。

#### 核心概念
2 的冪次方在二進位表示中只有一個位元為 1：
- 1 = 2^0 → `0001`
- 2 = 2^1 → `0010`  
- 4 = 2^2 → `0100`
- 8 = 2^3 → `1000`

#### 關鍵技巧：`n & (n-1)`
對於任何 2 的冪次方 n，`n & (n-1) = 0`：

#### 1st 想法:
1. early return : 
    * 當 n == 1 時 return True
    * 當 n < 0 or n == 0 時 return false
2. 若 n > 1前， 若 n 不是 2 的冪次方 ，此時 n & 1 在某一次一定會 = 1 , 此時return false

#### 優化演算法步驟
1. 檢查 `n > 0`（負數和 0 都不是 2 的冪次方）
2. 檢查 `(n & (n-1)) == 0`
3. 兩個條件都滿足則為 2 的冪次方

### 複雜度分析
- **時間複雜度**：O(1) - 只需要一次位元運算
- **空間複雜度**：O(1) - 不使用額外空間

## 重要概念

### 位元運算基礎
- `&` (AND)：兩個位元都為 1 時結果為 1
- `n & (n-1)`：清除 n 的最右邊的 1 位元

