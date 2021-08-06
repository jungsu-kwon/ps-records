from collections import defaultdict
from typing import List, DefaultDict, Dict, Set, Any

def solution(n: int, costs: List[List[int]]):
    sortedCosts: List[List[int]] = sorted(costs,
        key=lambda x: x[2])
    notConnected: Set[int] = set(range(n))

    cheapestBridge: List[int] = sortedCosts[0]
    src,dst,cost = cheapestBridge
    notConnected.discard(src)
    notConnected.discard(dst)

    ans: int = cost
    while notConnected:
        for i,(src,dst,cost) in enumerate(sortedCosts):
            if not src in notConnected and\
                not dst in notConnected:
                continue
            # already used
            if cost == -1:
                continue

            if not src in notConnected or\
                not dst in notConnected:
                notConnected.discard(dst)
                notConnected.discard(src)
                ans += cost
                sortedCosts[i][2] = -1
                break

    return ans
        
ans = solution(4,[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]])
print(ans)


