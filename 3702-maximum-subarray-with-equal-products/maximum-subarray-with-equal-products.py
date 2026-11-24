import math
from typing import List

class Solution:
    def maxLength(self, nums: List[int]) -> int:
        max_len = 2
        prod = 1
        left = 0

        for right, num in enumerate(nums):
            while math.gcd(prod, num) > 1:
                prod //= nums[left]
                left += 1
            
            prod *= num
            max_len = max(max_len, right - left + 1)

        return max_len