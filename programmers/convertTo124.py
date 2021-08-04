from typing import List, Dict

def solution(n: int) -> int:
    if n == 1: return 1
    triary: List[int] = []

    # convert to triary representation
    while n:
        remainder: int = n % 3
        n -= remainder
        n = n // 3
        triary.append(remainder)

    # remove zeros in triary number
    carry: int = 0
    for i,bit in enumerate(triary):
        triary[i] += carry
        if triary[i] <= 0 and i < len(triary) - 1:
            triary[i] += 3
            carry = -1
        else:
            carry = 0

    # remove leading zero
    if triary[-1] == 0:
        triary.pop(-1)
    
    # define mapping between 3ary -> 124
    converter: Dict[int,str] = {1:'1',2:'2',3:'4'}
    ans: str = ''.join([converter[bit] for bit in triary[::-1]])

    return ans


if __name__ == "__main__":
    for i in range(1,10):
        ans = solution(i)
        print(i,ans)
    

    


