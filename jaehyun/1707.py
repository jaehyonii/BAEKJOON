import sys
from collections import deque

def BFS(V, E):
	graph = [[] for _ in range(V + 1)]
	color = [0 for _ in range(V + 1)]
	
	# make graph
	for _ in range(E):
		u, v = map(int, sys.stdin.readline().split())
		graph[u].append(v)
		graph[v].append(u)
	
	# BFS
	dq = deque()
	for i in range(1, V + 1):
		if color[i] != 0:
			continue

		color[i] = 1
		dq.append(i)
		while dq:
			front = dq.popleft()
			
			for adj in graph[front]:
				if color[adj] == 0 :
					color[adj] = -color[front]
					dq.append(adj)
				elif color[adj] == color[front]:
					return False
	return True

K = int(sys.stdin.readline())
for _ in range(K):
	V, E = map(int, sys.stdin.readline().split())
	
	if(BFS(V, E)):
		print("YES")
	else:
		print("NO")