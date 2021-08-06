from typing import Any
class ListNode:
    def __init__(self,
        val: int = None,
        nextNode: 'ListNode' = None,
        prevNode: 'ListNode' = None):
        self.val: Any[int, float] = val
        self.next: 'ListNode' = nextNode
        self.prev: 'ListNode' = prevNode


def solution(operations):
    answer = []
    preHead: ListNode = ListNode(val=float('-inf'))
    postTail: ListNode = ListNode(val=float('inf'),prevNode=preHead)
    preHead.next = postTail
    count: int = 0

    def removeMax():
        removeNode = postTail.prev
        postTail.prev = removeNode.prev
        postTail.prev.next = postTail

    def removeMin():
        removeNode = preHead.next
        preHead.next = removeNode.next
        preHead.next.prev = preHead

    def insertNum(num: int):
        curNode: ListNode = preHead
        nextNode: ListNode = preHead.next
        while not curNode.val <= num <= nextNode:
            curNode = curNode.next
            nextNode = nextNode.next
        insertNode: ListNode = ListNode(num,
            nextNode=nextNode,
            prevNode=curNode)

        curNode.next = insertNode
        nextNode.prev = insertNode

    for op in operations:
        command, num = op.split(' ')
        num: int = int(num)
        if command == 'I':
            insertNum(num)
            count += 1
        elif count == 0:
            continue
        elif num == -1:
            removeMin()
            count -= 1
        else:
            removeMax()
            count -= 1
    if count == 0:
        return [0,0]
    return [preHead.next.val,postTail.prev.val]