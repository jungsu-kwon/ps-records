from typing import List

def solution(numbers: List[int] , target: int) -> int:
    answer: int = 0
    bfs: List[int] = [0]

    for number in numbers:
        nextLevel: List[int] = []

        for node in bfs:
            nextLevel.append(node + number)
            nextLevel.append(node - number)
        bfs = nextLevel
    
    return sum([num == target for num in bfs])