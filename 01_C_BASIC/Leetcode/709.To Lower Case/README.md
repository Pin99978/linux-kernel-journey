# 709. To Lower Case

## 問題描述
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

**Example:**
- Input: s = "Hello"
- Output: "hello"
- Input: s = "LOVELY"
- Output: "lovely"

## 解題思路

### ASCII 字符轉換法 (Character Conversion)
利用 ASCII 字符編碼的特性：
- 大寫字母 'A'-'Z' 的 ASCII 值為 65-90
- 小寫字母 'a'-'z' 的 ASCII 值為 97-122
- 大寫與小寫字母間的差值固定為 32

### 演算法步驟
1. 遍歷字串中的每個字符
2. 檢查字符是否為大寫字母 (ASCII 65-90)
3. 如果是大寫字母，將其 ASCII 值加 32 轉為小寫
4. 原地修改字串並返回

## 基礎知識

### ASCII 字符編碼
```c
// 大寫字母範圍
'A' = 65, 'Z' = 90

// 小寫字母範圍  
'a' = 97, 'z' = 122

// 轉換公式
lowercase = uppercase + 32
```

### In-place Modification
- 直接在原字串上進行修改
- 不使用額外的記憶體空間
- 空間複雜度為 O(1)

## 複雜度分析
- **時間複雜度**：O(n)，其中 n 是字串長度
- **空間複雜度**：O(1)，只使用常數額外空間

