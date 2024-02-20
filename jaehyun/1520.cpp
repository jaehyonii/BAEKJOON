#include <iostream>

using namespace std;

int **map;
int **dp;
int M, N; // size of map

int dfs(int r, int c)
{
	if (r == M - 1 && c == N - 1)
		return 1;
	if (dp[r][c] != -1)
		return dp[r][c];

	dp[r][c] = 0;
	if (r - 1 >= 0 && map[r - 1][c] < map[r][c])
		dp[r][c] += dfs(r - 1, c);
	if (r + 1 < M && map[r + 1][c] < map[r][c])
		dp[r][c] += dfs(r + 1, c);
	if (c - 1 >= 0 && map[r][c - 1] < map[r][c])
		dp[r][c] += dfs(r, c - 1);
	if (c + 1 < N && map[r][c + 1] < map[r][c])
		dp[r][c] += dfs(r, c + 1);

	return dp[r][c];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N;
	// make map
	map = new int *[M];
	dp = new int *[M];
	map[0] = new int[M * N];
	dp[0] = new int[M * N];
	for (int i = 1; i < M; i++)
	{
		map[i] = &map[0][N * i];
		dp[i] = &dp[0][N * i];
	}

	// get map
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}

	cout << dfs(0, 0);

	// delete map
	delete[] map[0];
	delete[] map;
	delete[] dp;

	return 0;
}