## 說明:

對 unsigned 數值而言

假設 unsigned x , unsigned y

unsigned sum = x + y ;

1. 在C中， unsigned 加法 以 $2^w$ (w 為位元數) 的 模數運算，如果發生 overflow 則  x + y - $2^w$ = sum  (結果顯示)
2. 若沒發生 overflow 則 sum = x + y ，因為 $y \ge 0$ 所以必定 $sum \ge x$ 
3. 若發生 overflow : x + y = sum + $2^w$ , 結果會比兩個加數都小

舉例:
* x=5, y=7 → 5+7=12（沒溢位）→ sum=12 ≥ x(5) 
* x=9, y=6 → 9+6=15（沒溢位）→ sum=15 ≥ x(9)
* x=12, y=7 → 12+7=19 → 環回 sum=19−16=3（溢位）→ 3 < x(12) 
* x=15, y=1 → 15+1=16 → 環回 sum=0（溢位）→ 0 < x(15) 