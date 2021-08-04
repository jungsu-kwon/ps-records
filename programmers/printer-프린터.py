from collections import namedtuple, deque
from typing import List, Deque, NamedTuple
import heapq

Document = namedtuple("document",["uid","priority"])
def solution(priorities: List[int], location: int):
    docs: List[Document] = [Document(i,p) 
        for i,p in enumerate(priorities)]
    
    negPriorities: List[int] = [-p for p in priorities]
    heapq.heapify(negPriorities)

    count: int = 0
    docsQueue: Deque[Document] = deque(docs)
    while True:
        while docsQueue[0].priority != -negPriorities[0]:
            docsQueue.append(docsQueue.popleft())

        count += 1
        heapq.heappop(negPriorities)
        printedDoc: Document = docsQueue.popleft()
        if printedDoc.uid == location:
            return count
    return -1

if __name__ == "__main__":
    priorities: List[int] = [1, 1, 9, 1, 1, 1]
    location: int = 0
    ans = solution(priorities,location)
    print(ans)

    
    
