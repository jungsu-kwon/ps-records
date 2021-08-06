from collections import deque, namedtuple
from typing import List, Deque

Price = namedtuple("price",["second","price"])

def solution(prices: List[int]):
    numSecs: int = len(prices)
    ans: List[int] = [0 for i in range(numSecs)]
    priceStack: Deque[Price] = deque()

    prevPrice: int = prices[0]
    for second,price in enumerate(prices):
        if price < prevPrice:
            while priceStack and priceStack[-1].price > price:
                poppedPrice: Price = priceStack.pop()
                ans[poppedPrice.second] =\
                    second - poppedPrice.second
        else:
            priceStack.append(Price(second,price))
        prevPrice = price

    while priceStack:
        poppedPrice: Price = priceStack.pop()
        ans[poppedPrice.second] =\
            numSecs - 1 - poppedPrice.second
    return ans