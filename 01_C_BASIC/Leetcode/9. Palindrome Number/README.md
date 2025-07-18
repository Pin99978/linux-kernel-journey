# 9. Palindrome Number

## 問題描述
Given an integer x, return true if x is a palindrome, and false otherwise.

### Follow up: Could you solve it without converting the integer to a string?
- 不使用轉型直接以數值確認是否為 Palindrome Number

### 時間複雜度分析
- **時間複雜度**：O(n)，其中 n 是陣列的長度
- **空間複雜度**：O(1)，只使用常數額外空間


### 第一次解法：Python + 字串轉換 + 雙指針
**時間複雜度**：O(n)  
**空間複雜度**：O(1)

``` python 
class Solution:
    def isPalindrome(self, x: int) -> bool:

        x = str(x)
        j = len(x) - 1 
        for i in range(len(x)):
            if x[i] != x[j] :
                return False
            if i > j :
                break
            j = j - 1

        return True
```

### 第二次解法：C + 數值反轉
**時間複雜度**：O(log n)  
**空間複雜度**：O(1)
```C
    while (x > 0){
        remainder = x % 10;
        reverse = reverse * 10 + remainder;
        x = x / 10;
    }
// check rest of code in C
```