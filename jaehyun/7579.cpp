#include <iostream>

using namespace std;

int *dp;

// idea: 최소비용으로 최소 M이상의 공간을 마련 -> 최대 K(= m_max-M)까지의 공간을 최대비용으로 마련
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int m[101];
	int c[101];
	int m_max = 0;
	int c_max = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> m[i];
		m_max += m[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> c[i];
		c_max += c[i];
	}

	int K = m_max - M;
	dp = new int[K + 1];
	for (int i = 0; i <= K; i++) // initialize
		dp[i] = 0;

	// kanpsack problem
	for (int i = 1; i <= N; i++)
	{
		for (int j = K; j >= 0; j--)
		{
			if (j < m[i])
				continue;
			if (dp[j] < dp[j - m[i]] + c[i])
				dp[j] = dp[j - m[i]] + c[i];
		}
	}

	cout << c_max - dp[K];

	delete[] dp;

	return 0;
}