#include <iostream>

using namespace std;

void reverse(int *arr, int s, int e)
{
	for (int k = 0; k < (e - s) / 2 + 1; k++)
	{
		int tmp = arr[s - 1 + k];
		arr[s - 1 + k] = arr[e - 1 - k];
		arr[e - 1 - k] = tmp;
	}
}

int main()
{
	int n, m;
	int s, e;
	cin >> n >> m;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		reverse(arr, s, e);
	}

	cout << arr[0];
	for (int i = 1; i < n; i++)
		cout << ' ' << arr[i];

	return 0;
}