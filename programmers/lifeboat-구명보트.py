from typing import List

def solution(people: List[int], limit: int) -> int:
    people: List[int] = sorted(people,reverse=True)
    numBoats: int = 0
    left: int = 0
    right: int = len(people) - 1

    while left < right:
        if people[left] + people[right] <= limit:
            left += 1
            right -= 1
        else:
            left += 1
        numBoats += 1
    
    return numBoats + int(left == right)

if __name__ == "__main__":
    ans:int = solution([70, 50, 80, 50],100)
    print(ans)






        
