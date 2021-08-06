from itertools import permutations
from typing import Set, List

def is_prime(n: int) -> bool:
    if n == 2 or n == 3: return True
    if n < 2 or n%2 == 0: return False
    if n < 9: return True
    if n%3 == 0: return False
    r = int(n**0.5)
    f = 5
    while f <= r:
        if n % f == 0: return False
        if n % (f+2) == 0: return False
        f += 6
    return True 

def solution(numbers):
    primeSet: Set[int] = set()
    for strLen in range(1,len(numbers)+1):
        for permutation in permutations(numbers,strLen):
            cand: int = int(''.join(permutation))
            if is_prime(cand):
                primeSet.add(cand)


    return len(primeSet)

ans = solution("17")
print(ans)