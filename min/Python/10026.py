import sys
from collections import deque

def BFS(x, y):
    target = arr[x][y]
    deq = deque()
    deq.append([x,y])
    visited[x][y]=True

    while(deq):
        tmp = deq.popleft()
        for i in range(4):
            new_x = tmp[0] + dx[i]
            new_y = tmp[1] + dy[i]
            if(new_x >=0 and new_x < n and new_y >=0 and new_y <n):
                if(visited[new_x][new_y]==False and arr[new_x][new_y]==target):
                    deq.append([new_x, new_y])
                    visited[new_x][new_y]=True
    
n = int(sys.stdin.readline())
arr = [] #색깔
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
visited = [[False]*n for _ in range (n)] #방문여부

for i in range(n):
    str = sys.stdin.readline()
    arr.append(list(str.strip()))

ans1 = 0
ans2 = 0

for i in range(n):
    for j in range(n):
        if(visited[i][j]==False):
            BFS(i,j)
            ans1+=1

for i in range(n):
    for j in range(n):
        if(arr[i][j]=='G'): #green인 경우
            arr[i][j] = 'R' #red로 변경

visited = [[False]*n for _ in range (n)] #방문여부            

for i in range(n):
    for j in range(n):
        
        if(visited[i][j]==False):
            BFS(i,j)
            ans2+=1

print(ans1, ans2)

