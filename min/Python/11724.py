import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
arr = [[0 for j in range(n+1)] for i in range(n+1)]
visited = [False for i in range(n+1)]

start = 0
end = 0

for i in range(m):
    start, end = map(int, sys.stdin.readline().split())
    arr[start][end]=1
    arr[end][start]=1

ans = 0
queue = deque()
for i in range(1, n+1):
    if(visited[i] == False):
        visited[i] = True
        queue.append(i)
        while(len(queue)!=0):
            front = queue[0]
            for j in range(1, n+1):
                if(arr[front][j]==1 and visited[j] == False):
                    queue.append(j)
                    visited[j] = True
            queue.popleft()
        ans+=1

print(ans)
