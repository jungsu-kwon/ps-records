from collections import Counter
def solution(participant, completion):
    counter: Counter[str] = Counter(completion)
    for name in participant:
        if name not in counter:
            return name
        elif counter[name] == 0:
            return name
        else:
            counter[name] -= 1
        
    return ""