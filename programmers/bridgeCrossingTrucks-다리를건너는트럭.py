from collections import deque, namedtuple
from typing import List, Deque


Truck = namedtuple("truck",["weight","outTime"])
def solution(bridge_length: int, weight: int, truck_weights: List[int]) -> int:
    # define basic constants
    timeToCrossBridge: int = bridge_length
    curWeight: int = 0
    numTrucks: int = len(truck_weights)

    # define datastructure
    truckQueue: Deque[Truck] = deque()
    truckIndex: int = 0
    curTime: int = 0

    while truckIndex < numTrucks:
        truckWeight: int = truck_weights[truckIndex]
        if truckQueue and truckQueue[0].outTime == curTime:
            curWeight -= truckQueue.popleft().weight

            if curWeight + truckWeight <= weight:
                truckQueue.append(Truck(truckWeight,
                    curTime+bridge_length))
                curWeight += truckWeight
                truckIndex += 1

            curTime += 1

        elif curWeight + truckWeight <= weight:
            truckQueue.append(Truck(truckWeight,
                curTime+bridge_length))
            curWeight += truckWeight
            truckIndex += 1
            curTime += 1
        
        else:
            curTime = truckQueue[0].outTime

    return truckQueue[-1].outTime+1

if __name__ == "__main__":
    bridgeLens: List[int] = [2,100,100]
    weights: List[int] = [10,100,100]
    truck_weightss: List[List[int]] = [[7,4,5,6],[10],[10,10,10,10,10,10,10,10,10,10]]

    for bridgeLen, weight, truck_weights in zip(bridgeLens,weights,truck_weightss):
        ans = solution(bridgeLen,weight,truck_weights)
        print(ans)
        

