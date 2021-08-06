from typing import List

def solution(routes: List[List[int]]) -> int:
    sortedRoutes: List[List[int]] = sorted(
        routes, key = lambda x : x[0]
    )
    def intersection(r1:List[int],r2:List[int]) -> List[int]:
        early, later = sorted([r1,r2])
        s1,e1 = early
        s2,e2 = later
        if s2 <= e1: return [s2,min(e1,e2)]
        return []
    
    ind: int = 0
    count: int = 1
    curInter: List[int] = sortedRoutes[0]

    while ind < len(routes):
        route: List[int] = sortedRoutes[ind]
        curInter: List[int] = intersection(curInter,route)\
            if curInter else route

        if not curInter:
            curInter = route
            count += 1
        ind += 1
    return count
        



        


if __name__ == "__main__":
    routes: List[List[int]] = [[-20,15], [-14,-5], [-18,-13], [-5,-3]]
    ans = solution(routes)
    print(ans)

