# 26. Remove Duplicates from Sorted Array

## 問題描述
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.

## 重要概念

### 雙指針技巧 (Two Pointers)
- **慢指針 (slow)**：指向下一個不重複元素應該放置的位置
- **快指針 (fast)**：用於遍歷整個陣列
- 當 `nums[fast] != nums[slow]` 時，將 `nums[fast]` 複製到 `nums[slow+1]`

### 原地修改 (In-place Modification)
- 不使用額外的陣列空間
- 直接在原陣列上進行修改
- 空間複雜度為 O(1)

### 時間複雜度分析
- **時間複雜度**：O(n)，其中 n 是陣列的長度
- **空間複雜度**：O(1)，只使用常數額外空間
