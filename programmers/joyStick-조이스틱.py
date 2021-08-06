from string import ascii_uppercase
from typing import Dict
def solution(name: str) -> int:
    numChars: int = len(ascii_uppercase)
    converter: Dict[str,int] = {ch:min(i % numChars,-i %  numChars)
        for i,ch in enumerate(ascii_uppercase)}
    print(converter)
    
    startA: int = -1
    endA: int = -1

    ans: int = len(name) - 1
    for i,ch in enumerate(name):
        if ch == "A":
            startA = i
            endA = i
            while endA < len(name) and name[endA] == "A":
                endA += 1
            ans = min(ans,
                len(name) - endA + (2*max(startA-1,0)))

    ans += sum([converter[ch] for ch in name])
    
    return ans
solution("A")