#include <iostream>

using namespace std;

bool checkDup(int *arr, int idx, int n)
{
	for (int i = 0; i < idx; i++)
	{
		if (arr[i] == n)
			return true;
	}
	return false;
}

void dfs(int *arr, int idx, int N, int M)
{
	if (idx < M)
	{
		for (int i = 1; i <= N; i++)
		{
			if (!checkDup(arr, idx, i))
			{
				arr[idx] = i;
				dfs(arr, idx + 1, N, M);
			}
		}
	}
	else
	{
		cout << arr[0];
		for (int i = 1; i < M; i++)
			cout << ' ' << arr[i];
		cout << '\n';
	}
}

int main()
{
	int N, M; // N : max, M : digit
	cin >> N >> M;

	int *arr = new int[M];
	dfs(arr, 0, N, M);

	return 0;
}