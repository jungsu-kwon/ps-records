from typing import List
import heapq

def solution(scovilles: List[int], K: int) -> int:
    heapq.heapify(scovilles)

    count: int = 0
    while scovilles and scovilles[0] <= K:
        if len(scovilles) == 1:
            return -1
        else:
            first: int = heapq.heappop(scovilles)
            second: int = heapq.heappop(scovilles)
            heapq.heappush(first + (2*second))
            count += 1

    return count