import sys

from collections import deque

n = int(sys.stdin.readline())
graph = [[] for i in range(n+1)]
parent = [0 for i in range(n+1)]
visited = [False for i in range(n+1)]

for i in range(n-1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

q = deque()

q.append(1)
visited[1] = True

while q:
    front = q.popleft()
    for i in graph[front]:
        if(visited[i]==False):
            parent[i]=front
            q.append(i)
            visited[i]=True
                
for i in range(2, n+1):
    print(parent[i])
