from typing import List
from math import ceil

def solution(progresses: List[int], speeds: List[int]):
    ans: List[int] = []
    ind: int = 0

    def getRemainingDays(ind: int) -> int:
        progress: int = progresses[ind]
        speed: int = speeds[ind]
        return ceil((100 - progress) / float(speed))

    while ind != len(progresses):
        curRemainingDays: int = getRemainingDays(ind)
        nextInd: int = ind

        while nextInd < len(progresses) and\
            curRemainingDays >= getRemainingDays(nextInd):
            nextInd += 1

        ans.append(nextInd - ind)
        ind = nextInd

    return ans

if __name__ == "__main__":
    inProgresses: List[List[int]] = [[93, 30, 55],
        [95, 90, 99, 99, 80, 99],
        [1],
        []]
    inSpeeds: List[List[int]] = [[1,30,5],
        [1,1,1,1,1,1],
        [1],
        []]

    for progresses, speeds in zip(inProgresses,inSpeeds):
        ans = solution(progresses, speeds)
        print(ans)

