from typing import Dict

class TrieNode:
    def __init__(self):
        self.children: Dict[str,TrieNode] = {}
        self.isWord = False

def solution(phone_book):
    root: TrieNode = TrieNode()
    for num in phone_book:
        curNode: TrieNode = root
        created: bool = False
        for digit in num:
            if digit not in curNode.children:
                curNode.children[digit] = TrieNode()
                created = True
            curNode = curNode.children[digit]
            if curNode.isWord:
                return False
        curNode.isWord = True
        if not created:
            return False


    return True