from typing import List
from collections import Counter
def solution(clothes: List[List[str]]) -> int:
    counter: Counter = Counter([cloth[1] for cloth in clothes])
    counts: List[int] = list(counter.values())
    ans: int = 1
    for count in counts:
        ans *= count
    return ans - 1