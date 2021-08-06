import math
def divisors(n):
    divs = [(1,n)]
    for i in range(2,int(math.sqrt(n))+1):
        if n%i == 0:
            divs.append((i,int(n/i)))
    return divs

def solution(brown: int, yellow: int):
    numGrids: int = brown + yellow
    for h,w in divisors(numGrids):
        border: int = 2*h + 2*w - 4
        center: int = (h-2) * (w-2)
        if border == brown and center == yellow:
            return [w,h]

ans = solution(10,2)
print(ans)