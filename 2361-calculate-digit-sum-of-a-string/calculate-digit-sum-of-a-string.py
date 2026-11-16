class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            new_parts = []
            for i in range(0, len(s), k):
                group = s[i:i + k]
                digit_sum = sum(int(char) for char in group)
                new_parts.append(str(digit_sum))
            s = "".join(new_parts)
        return s