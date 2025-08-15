class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        n = len(nums)
        
        if n == 1:
            return nums
        
        i = n - 2
        
        while (i >= 0 and nums[i] >= nums[i+1]):
            i = i -1
            
        if i == -1:
            nums.reverse()
            return 
        
        j = n - 1
        while nums[j] <= nums[i]:
            j -=1
            
        nums[i], nums[j] = nums[j], nums[i]
        
        nums[i+1:] = reversed(nums[i+1:])