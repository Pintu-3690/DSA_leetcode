class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        count = len(arr1)
        for i in arr1:
            for j in arr2:
                if abs(i - j) <= d:
                    count -= 1
                    break
        return count