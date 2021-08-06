from typing import List
from collections import namedtuple
import heapq

Job = namedtuple("job",["processTime","inTime"])

def solution(jobs: List[List[int]]) -> int:
    # define default constants
    numJobs: int = len(jobs)
    pendingJobs: List[Job] = []

    # define loop related variables
    delay: int = 0
    curTime: int = 0
    start: int = -1
    jobIndex: int = 0

    while jobIndex < numJobs:
        for job_ in jobs:
            job: Job = Job(*job_[::-1])
            if start < job.inTime <= curTime:
                heapq.heappush(pendingJobs,job)

        if pendingJobs:
            jobToQueue: Job = heapq.heappop(pendingJobs)
            start = curTime
            curTime += jobToQueue.processTime
            delay += curTime - jobToQueue.inTime
            jobIndex += 1
        else: curTime += 1
    
    return delay // numJobs