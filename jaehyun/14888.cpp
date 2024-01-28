#include <iostream>

using namespace std;

int minn = 1000000001;
int maxx = -1000000001;

void dfs(int *arr, int idx, int p, int mi, int mul, int d, int res) // idx starts at 1, res starts at arr[0]
{
	if (p > 0)
		dfs(arr, idx + 1, p - 1, mi, mul, d, res + arr[idx]);
	if (mi > 0)
		dfs(arr, idx + 1, p, mi - 1, mul, d, res - arr[idx]);
	if (mul > 0)
		dfs(arr, idx + 1, p, mi, mul - 1, d, res * arr[idx]);
	if (d > 0)
		dfs(arr, idx + 1, p, mi, mul, d - 1, res / arr[idx]);

	if (p == 0 && mi == 0 && mul == 0 && d == 0)
	{
		if (minn > res)
			minn = res;
		if (maxx < res)
			maxx = res;
	}
}

int main()
{
	int N;
	cin >> N;

	int *arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int cal[4]; // + - * /
	for (int i = 0; i < 4; i++)
		cin >> cal[i];

	dfs(arr, 1, cal[0], cal[1], cal[2], cal[3], arr[0]);

	cout << maxx << '\n'
		 << minn;

	return 0;
}