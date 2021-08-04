from math import log10, floor
from typing import List
def solution(s: str) -> int:

    def computeCompressionLen(prefixLen: int) -> int:
        splits: List[str] = [s[prefixLen*i:(i+1)*prefixLen] 
            for i in range(len(s) // prefixLen)]
        remainderLen: int = len(s) - prefixLen * len(splits)

        ans: int = remainderLen
        curPrefix: str = splits[0]
        count: int = 0

        for split in splits + [""]:
            if curPrefix == split:
                count += 1
            else:
                ans += floor(log10(count)) + 1 + prefixLen if count >= 2 else prefixLen
                curPrefix = split
                count = 1

        return ans
    return min([computeCompressionLen(i) for i in range(1,len(s) // 2 + 1)])
if __name__ == '__main__':
    words: List[str] = ["aabbaccc","ababcdcdababcdcd","abcabcdede","abcabcabcabcdededededede"]
    for word in words:
        ans = solution(word)
        print(word,ans)