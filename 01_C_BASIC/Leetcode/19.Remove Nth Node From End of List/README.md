## Leetcode 19 - remove N-th Node From End of __va_list_tag

### 1st attempt
- 用雙指標, 1st ptr得到length 並得到n位置的element(target) , 2st ptr從dummy到target後移除target

- Bug : 未考慮到head 的行為


### 2nd 快慢針方法
- Used two-pointer trick to do it in one pass.