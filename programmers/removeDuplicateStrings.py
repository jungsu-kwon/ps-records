from typing import List
def solution(s: str) -> int:
    if not s: 
        return 1
    
    strList: List[str] = list(s)
    while strList:
        prevInd: int = None
        curInd: int = 0
        removeCount: int = 0

        while curInd != len(strList):
            ch: str = strList[curInd]

            if prevInd is not None and strList[prevInd] == strList[curInd]: 
                strList[prevInd] = ""
                strList[curInd] = ""

                prevInd = prevInd - 1 if prevInd else None
                curInd += 1
                removeCount += 1

            else: 
                prevInd = curInd
                curInd += 1
        
        if not removeCount: return 0
        strList: List[str] = [ch for ch in strList if ch]


    return 1

if __name__ == "__main__":
    for word in ["aaacaaac","baabaa","cdcd"]:
        ans = solution(word)
        print(word,ans)