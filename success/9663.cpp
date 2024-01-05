#include <iostream>
#include <algorithm>

using namespace std;

bool checkPossiblity(int *arr, int row, int col, int N)
{
	for (int i = 0; i < row; i++)
	{
		if (arr[i] == col || row - i == col - arr[i] || row - i == arr[i] - col)
			return false;
	}

	return true;
}

void dfs(int *arr, int row, int N, int &num)
{
	if (row < N)
	{
		for (int col = 0; col < N; col++)
		{
			if (checkPossiblity(arr, row, col, N))
			{
				arr[row] = col;
				dfs(arr, row + 1, N, num);
			}
		}
	}
	else
	{
		num++;
	}
}

int main()
{
	int N;
	cin >> N;

	int num = 0;

	int *arr = new int[N];
	fill(arr, arr + N, -20);

	dfs(arr, 0, N, num);

	cout << num;
	return 0;
}