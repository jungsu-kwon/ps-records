from typing import List
def solution(n: int, 
    losts: List[int], 
    reserves: List[int]) -> int:

    suits: List[int] = [1 for i in range(n)]
    for lost in losts:
        suits[lost-1] = 0
    for reserve in reserves:
        suits[reserve-1] = 2
    
    count: int = 0
    for i,suit in enumerate(suits):
        if suit == 0:
            if i == 0:
                if suits[1] == 2:
                    suits[1] = 1
                    suits[0] = 1
            elif i == n - 1:
                if suits[n-2] == 2:
                    suits[n-1] = 1
                    suits[n-2] = 1
            else:
                if suits[i-1] == 2:
                    suits[i] = 1
                    suits[i-1] = 1
                elif suits[i+1] == 2:
                    suits[i] = 1
                    suits[i+1] = 1
            if suits[i] == 0:
                count += 1
            
    

    return n - count
ans = solution(5,[2,4],[1,3,5])
print(ans)