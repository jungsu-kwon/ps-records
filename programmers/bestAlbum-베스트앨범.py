from collections import defaultdict, namedtuple
from typing import DefaultDict, List, Iterable
from heapq import nlargest

Song = namedtuple("song", ["songId","playCount"])

def solution(genres: List[str], plays: List[int]) -> List[int]:
    genreCounts: DefaultDict[str,int] = defaultdict(int)
    songs: DefaultDict[str,List[Song]] = defaultdict(list)

    for songId,(genre,playCount) in enumerate(zip(genres,plays)):
        genreCounts[genre] += playCount
        song = Song(songId,playCount)
        songs[genre].append(song)
    
    sortedGenres: Iterable[str] = sorted(genreCounts.keys(),
        key= lambda x: genreCounts[x],
        reverse=True)
    
    ans: List[int] = []
    for genre in sortedGenres:
        ans += [song.songId for song in 
            nlargest(2,songs[genre],key= lambda x: x.playCount)]
    return ans


if __name__ == "__main__":
    genres: List[str] = ["classic", "pop", "classic", "classic", "pop"]
    plays: List[int] = [500, 600, 150, 800, 2500]

    ans = solution(genres,plays)
    print(ans)
