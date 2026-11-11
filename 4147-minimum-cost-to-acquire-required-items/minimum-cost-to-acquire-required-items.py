class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        optionA = need1 * cost1 + need2 * cost2
        optionB = max(need1, need2) * costBoth
        
        common_need = min(need1, need2)
        optionC = (common_need * costBoth + 
                   (need1 - common_need) * cost1 + 
                   (need2 - common_need) * cost2)
        
        return min(optionA, optionB, optionC)
        