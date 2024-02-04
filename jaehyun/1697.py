from collections import deque

N, K = input().split()

N = int(N)
K = int(K)

dq = deque()
p = []
visited = [False] * 100001

p = [N, 0]
dq.append(p)
while dq:
	p = dq.popleft()
	if p[0] == K:
		break
	
	if p[0] - 1 >= 0 and p[0] - 1 <= 100000 and not visited[p[0] - 1] :
		dq.append([p[0] -1, p[1] + 1])
		visited[p[0] - 1] = True
	if p[0] + 1 >= 0 and p[0] + 1 <= 100000 and not visited[p[0] + 1] :
		dq.append([p[0] + 1, p[1] + 1])
		visited[p[0] + 1] = True
	if p[0] * 2 >= 0 and p[0] * 2 <= 100000 and not visited[p[0] * 2] :
		dq.append([p[0] * 2, p[1] + 1])
		visited[p[0] * 2] = True

print(p[1])