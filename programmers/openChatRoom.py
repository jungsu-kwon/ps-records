from typing import List, Dict
from collections import namedtuple

Action = namedtuple("action",["uid","action"])

def solution(record: List[str]) -> List[str]:
    # converter uid --> nickname
    converter: Dict["str","str"] = {}
    actions: List[Action] = []


    for action in record:
        splitted = action.split(' ')
        actionType = splitted[0]

        if actionType == 'Change':
            uid = splitted[1]
            converter[uid] = splitted[2]
            continue

        elif actionType == 'Enter':
            uid = splitted[1]
            converter[uid] = splitted[2]

        actions.append(Action(uid=splitted[1],action=splitted[0]))
    
    ans: List[str] = []
    for action in actions:
        if action.action == "Enter":
            ans.append(f'{converter[action.uid]}님이 들어왔습니다.')
        else:
            ans.append(f'{converter[action.uid]}님이 나갔습니다.')

    return ans 

if __name__ ="__main__":
