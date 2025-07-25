# 136. Single Number

## 問題描述
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

## 解題思路
使用 XOR 位元運算來解決這個問題。

### XOR 位元運算的重要性質：

1. **結合律**：`(a ^ b) ^ c = a ^ (b ^ c)`
2. **交換律**：`a ^ b = b ^ a`
3. **自反性**：`a ^ a = 0` (相同數字 XOR 結果為 0)
4. **恆等元**：`a ^ 0 = a` (任何數與 0 做 XOR 等於自己)

### 演算法原理
利用 XOR 的自反性，相同的數字進行 XOR 運算會得到 0，而任何數字與 0 進行 XOR 運算會得到原數字本身。

因此，將陣列中所有元素進行 XOR 運算：
- 出現兩次的元素會互相抵消 (變成 0)
- 最後只剩下出現一次的元素

## 範例演算

以 `[4,1,2,1,2]` 為例：

```
0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2
= 0 ^ 4 ^ (1 ^ 1) ^ (2 ^ 2)  // 利用交換律重新排列
= 0 ^ 4 ^ 0 ^ 0              // 利用自反性：相同數字 XOR = 0
= 4                          // 利用恆等元：任何數 ^ 0 = 自己
```


## 複雜度分析

- **時間複雜度**：O(n) - 需要遍歷整個陣列一次
- **空間複雜度**：O(1) - 只使用常數額外空間

