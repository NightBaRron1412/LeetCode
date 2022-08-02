class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        occurrences=[]
        found = False;
        
        for index, elem in enumerate(nums):
            if elem == target:
                found = True
                occurrences.append(index)
            
        if(found == False):
            return [-1, -1,]
        else:
            return [occurrences[0], occurrences[-1]]