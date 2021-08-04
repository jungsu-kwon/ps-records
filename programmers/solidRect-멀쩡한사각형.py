from math import ceil, floor, gcd
from typing import List

def computeBigFloat(mult:int, small: int):
    remainder: int = mult % small
    integer: int = (mult - remainder) // small
    return integer,remainder > 0


def solution(w:int ,h: int) -> int:
    def helper(big: int, small: int ) -> int:
        if big < small: return helper(small,big)
        div: int = gcd(big,small)
        if div != 1:
            return div * helper(big//div,small//div)

        ans = 0
        mult: int = 0
        for i in range(small):
            mult += big
            endInt,endRemainder = computeBigFloat(mult+big,small)
            startInt,startRemainder = computeBigFloat(mult,small)
            
            ans += endInt - startInt + int(endRemainder)

        return ans

    return w*h - helper(w,h)

if __name__ == "__main__":
    ans = solution(8,12)
    print(ans)