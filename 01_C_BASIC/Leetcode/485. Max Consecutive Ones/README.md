# 485. Max Consecutive Ones

## 問題描述
Given a binary array `nums`, return the maximum number of consecutive 1's in the array.

**Example:**
- Input: nums = [1,1,0,1,1,1]
- Output: 3

## 解題思路

### 一次遍歷計數法 (Single Pass Counting)
這題確實不難！只需要：
1. 遍歷陣列，遇到 1 就累計計數
2. 遇到 0 就重置計數為 0
3. 持續追蹤最大值

### 演算法步驟
1. 初始化 `sum = 0`（當前連續 1 的數量）和 `max = 0`（最大連續數量）
2. 遍歷每個元素：
   - 如果是 1：`sum++`
   - 如果是 0：`sum = 0`
   - 更新 `max = (sum > max) ? sum : max`

## 複雜度分析
- **時間複雜度**：O(n) - 只需遍歷一次陣列
- **空間複雜度**：O(1) - 只使用常數額外空間

## 重要概念
- **位元運算**：使用 `nums[i] & 1` 檢查是否為 1
- **一次遍歷**：簡單直觀的解法
- **滑動窗口概念**：雖然簡單，但體現了窗口重置的思想