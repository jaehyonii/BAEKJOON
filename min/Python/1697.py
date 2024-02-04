import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())
q = deque()
visited = [False for i in range(100001)]

q.append([n, 0])

while q:
    [length, time] = q.popleft()
    
    if(length==k):
        break;

    if(length*2 <= 100000 and visited[length*2]==False):
        q.append([length*2, time+1])
        visited[length*2]=True;

    if(length-1 >= 0 and visited[length-1]==False):
        q.append([length-1, time+1])
        visited[length-1]=True;

    if(length+1 <= 100000 and visited[length+1]==False):
        q.append([length+1, time+1])
        visited[length+1]=True;

print(time)
