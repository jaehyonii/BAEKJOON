import sys

N, M = map(int, sys.stdin.readline().split())
m = list(map(int, sys.stdin.readline().split()))
c = list(map(int, sys.stdin.readline().split()))
c_max = sum(c)

dp = [0 for _ in range(c_max + 1)]

for i in range(N):
	for j in range(c_max, -1, -1):
		if(j < c[i]):
			continue
		if(dp[j] < dp[j - c[i]] + m[i]):
			dp[j] = dp[j - c[i]] + m[i]

for i in range(c_max + 1):
	if(dp[i] >= M):
		print(i)
		break