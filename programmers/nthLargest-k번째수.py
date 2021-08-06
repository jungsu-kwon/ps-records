from typing import List
import heapq
def solution(array: List[int], commands: List[List[int]]) -> List[int]:
    ans: List[int] = []
    for start,end,k in commands:
        ans.append(heapq.nsmallest(k,array[start-1:end])[-1])
        
    return ans