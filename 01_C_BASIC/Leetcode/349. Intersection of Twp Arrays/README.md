# 349. Intersection of Two Arrays

## 問題描述
Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

**Example 1:**
```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

**Example 2:**
```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4] or [4,9]
```

**Constraints:**
- 1 <= nums1.length, nums2.length <= 1000
- 0 <= nums1[i], nums2[i] <= 1000

## 解題思路

### 雜湊表計數法 (Hash Table Counting)
利用陣列模擬雜湊表來標記元素的出現情況：
1. 創建一個計數陣列來追踪元素出現狀態
2. 遍歷第一個陣列，標記出現的元素
3. 遍歷第二個陣列，累加已標記的元素
4. 收集計數為 2 的元素（同時在兩個陣列中出現）

### 演算法步驟
1. 使用 `calloc()` 創建大小為 1001 的計數陣列，初始化為 0
2. 遍歷 `nums1`，將 `is_exist_arr[nums1[i]]` 設為 1
3. 遍歷 `nums2`，如果 `is_exist_arr[nums2[j]] == 1`，則增加計數
4. 遍歷計數陣列，收集計數為 2 的索引值
5. 返回結果陣列

## C 語言實作重點

### 記憶體分配策略
```c
int *is_exist_arr = calloc(MAXLENGTH + 1, sizeof(int));
int *arr = malloc(1001 * sizeof(int));
```

**關鍵概念：**
- 使用 [`calloc()`](https://man7.org/linux/man-pages/man3/malloc.3.html) 自動初始化為 0
- 分配大小為 1001 因為題目約束範圍為 0-1000

### 狀態標記技巧
```c
// 第一次遍歷：標記存在
is_exist_arr[nums1[i]] = 1;

// 第二次遍歷：累加計數
if (is_exist_arr[nums2[j]] == 1) {
    is_exist_arr[nums2[j]]++;
}
```

**演算法邏輯：**
- 值為 1：只在 `nums1` 中出現
- 值為 2：同時在兩個陣列中出現（交集）

## 複雜度分析
- **時間複雜度**：O(n + m + k)，其中 n 是 `nums1` 長度，m 是 `nums2` 長度，k 是範圍大小（1001）
- **空間複雜度**：O(k)，需要額外的計數陣列
