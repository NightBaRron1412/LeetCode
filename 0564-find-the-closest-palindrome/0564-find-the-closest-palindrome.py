class Solution:
    def nearestPalindromic(self, n: str) -> str:
        length = len(n)
        num = int(n)
        
        if num == 0:
            return "1"
        if num == 1:
            return "0"
        
        candidates = set()
        
        prefix = int(n[:(length + 1) // 2])
        
        for i in [-1, 0, 1]:
            p = str(prefix + i)
            if length % 2 == 0:
                palindrome = p + p[::-1]
            else:
                palindrome = p + p[:-1][::-1]
            candidates.add(int(palindrome))
        
        candidates.add(10**(length-1) - 1)
        candidates.add(10**length + 1)
        
        candidates.discard(num)
        
        nearest = min(candidates, key=lambda x: (abs(x - num), x))
        
        return str(nearest)