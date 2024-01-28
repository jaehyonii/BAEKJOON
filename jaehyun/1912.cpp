#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int *dp = new int[n];
	dp[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (dp[i - 1] + arr[i] < arr[i])
			dp[i] = arr[i];
		else
			dp[i] = dp[i - 1] + arr[i];
	}

	int max = dp[0];
	for (int i = 1; i < n; i++)
	{
		if (max < dp[i])
			max = dp[i];
	}

	cout << max;

	return 0;
}