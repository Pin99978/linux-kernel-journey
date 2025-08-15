# 31. Next Permutation

## 問題描述:
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]

### 思考:

因題目沒有寫得很清楚，從網路上查閱
example 1 
[1,2,3] -> [1,3,2]
[1,3,2] -> [2,1,3]
[2,1,3] -> [2,3,1]

題目想要的是 找到最後一個發生 n+1 > n 的位置，  n 需與 "最小"的值做置換後，n+1 to 最後的值 需以升序排序

1. 找位置: 從最右往回找到第一個  i+1 > i
    若找不到 : reverse all array
2. 找到最小替換數:，找的範圍 i+1 -> end
3. 將i+1 -> end 進行升序

