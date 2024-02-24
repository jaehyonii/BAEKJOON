#include <iostream>

using namespace std;

int *dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	dp = new int[K + 1];
	for (int i = 0; i < K + 1; i++)
		dp[i] = 0;

	int W, V;
	for (int i = 0; i < N; i++)
	{
		cin >> W >> V;

		for (int w = K; w > 0; w--)
		{
			if (w < W)
				continue;
			if (dp[w] < dp[w - W] + V)
				dp[w] = dp[w - W] + V;
		}
	}

	cout << dp[K];

	delete[] dp;

	return 0;
}