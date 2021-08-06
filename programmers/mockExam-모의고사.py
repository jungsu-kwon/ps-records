from collections import defaultdict
from typing import DefaultDict, List

first: List[int] = [1,2,3,4,5]
second: List[int] = [2,1,2,3,2,4,2,5]
third: List[int] = [3,3,1,1,2,2,4,4,5,5]

def getCount(pattern: List[int], answers: List[int]) -> int:
    patternLen: int = len(pattern)

    ans: int = 0
    for i,answer in enumerate(answers):
        if answer == pattern[i % patternLen]:
            ans += 1
    return ans

def solution(answers: List[int]) -> List[int]:
    patterns: List[List[int]] = [first,second,third]
    counts: DefaultDict[int,List] = defaultdict(list)

    for i,pattern in enumerate(patterns):
        counts[getCount(pattern,answers)].append(i+1)
    
    maxKey: int = max(counts.keys())
    return sorted(counts[maxKey])