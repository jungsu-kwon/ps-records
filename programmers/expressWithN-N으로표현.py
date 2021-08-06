from collections import defaultdict
from typing import DefaultDict, List, Set
def solution(N: int, number: int) -> int:
    numSets: DefaultDict[int,Set[int]] = defaultdict(set)
    stopNumber: int = 8
    numSets[1].add(N)

    def combineSets(s1:Set[int], s2:Set[int], res: Set[int]):
        for n1 in s1:
            for n2 in s2:
                res.add(n1+n2)
                res.add(n1-n2)
                res.add(n2-n1)
                res.add(n1*n2)
                if n2:
                    res.add(n1//n2)
                if n1:
                    res.add(n2//n1)

    for i in range(2,stopNumber+1):
        curSet: Set[int] = numSets[i]
        curSet.add(int(str(N)*i))

        for j in range(1,i):
            set1: Set[int] = numSets[j]
            set2: Set[int] = numSets[i-j]
            combineSets(set1,set2,curSet)
        if number in curSet:
            return i
    return -1





