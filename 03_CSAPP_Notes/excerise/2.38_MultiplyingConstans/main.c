#include <stdio.h>

/*
The LEA instruction can perform computations of the form (a << k) + b ,where k is either 0 ,1,2,3 . and b is either 0 or some program value , 
(*important) the compiler often uses this instruction to perform multiplications by constant factors . e.g we can compute 3*a as (a<<1) + a ->
a*3 = a*(2+1) = (a<<1) + a

Considering cases where b is eitehr 0 or equal to a , and all possible values of k, what multiples of a can be computed with a single LEA instruction?
考慮 b 為 0 或等於 a 的情況，以及 k 的所有可能值，使用單一 LEA 指令可以計算 a 的多少倍？

if b = 0 (a << k) in 32 bit -> a * 31 =  
if b = a (a << k) + a = 
*/