import bisect
from typing import List
def solution(citations: List[int]) -> int:
    sortedCites: List[int] = sorted(citations)

    left: int = 0
    right: int = max(sortedCites[-1],len(sortedCites))
    ans: int = 0

    while left < right:
        mid: int = (left + right) // 2
        foundInd: int = bisect.bisect_left(sortedCites,mid)
        lessCount: int = foundInd
        geCount: int = len(citations) - lessCount

        if geCount < mid:
            right = mid - 1
        else:
            ans = max(ans,mid)
            left += 1
    return ans

if __name__ == "__main__":
    ans = solution([3,0,6,1,5])
    print(ans)

        

    