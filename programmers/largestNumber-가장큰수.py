from math import log10
from typing import List

def solution(numbers):
    sortedArr: List[int] = sorted(numbers,key=lambda x: 3*str(x),reverse=True)
    if sortedArr[0] == 0:
        return '0'
    return ''.join([str(num) for num in sortedArr])