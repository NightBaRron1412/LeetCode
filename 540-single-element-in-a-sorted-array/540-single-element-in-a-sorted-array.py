class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        c = Counter(nums)
        for num in nums:
            if (c[num] == 1):
                return num