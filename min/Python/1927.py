import sys
from queue import PriorityQueue

n = int(sys.stdin.readline())
pq = PriorityQueue()

for i in range(n):
    num = int(sys.stdin.readline())
    if(num==0):
        if(pq.empty()):
            print(0)
        else:
            print(pq.get())
    else:
        pq.put(num)
