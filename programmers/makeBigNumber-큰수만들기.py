from collections import deque
from typing import Deque, List

def solution(number, k):
    if len(number) == 1: return ''
    curInd: int = 0
    end: Deque[int] = deque([int(ch) for ch in number])
    front: Deque[int] = deque()
    front.append(end.popleft())

    while k:
        if front and front[-1] < end[0]:
            front.pop()
            front.append(end.popleft())
            k -= 1

            if front:
                end.appendleft(front.pop())
        else:
            front.append(end.popleft())
    
    return ''.join([str(ch) for ch in list(front)+list(end)])
ans = solution("4177252841",4)   
print(ans)