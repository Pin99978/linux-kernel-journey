class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        is_exist = {}

        for i in nums1:
            if i not in is_exist.keys():
                is_exist[i] = 0
            
        for i in nums2:
            if i in is_exist.keys():
                is_exist[i] = 1

        arr = []
        for key , val in is_exist.items():
            if val == 1:
                arr.append(key)
        return arr
        