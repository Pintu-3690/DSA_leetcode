import heapq
from typing import List
from sortedcontainers import SortedList

class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        busy = []                 
        free = SortedList(range(k))  
        request_count = [0] * k
        
        for i, (start, t) in enumerate(zip(arrival, load)):
            while busy and busy[0][0] <= start:
                _, server = heapq.heappop(busy)
                free.add(server)
            
            if not free:
                continue
            
            idx = free.bisect_left(i % k)
            
            if idx == len(free):
                idx = 0
                
            server = free[idx]
            free.remove(server)
            
            request_count[server] += 1
            heapq.heappush(busy, (start + t, server))
            
        max_requests = max(request_count)
        return [i for i, count in enumerate(request_count) if count == max_requests]