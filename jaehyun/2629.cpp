#include <iostream>

using namespace std;

bool **bead;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N; // the number of pendulu
	cin >> N;
	int pendulum[31];
	int max = 0; // the max value which can be made with pendulums
	for (int i = 1; i <= N; i++)
	{
		cin >> pendulum[i]; // the weight of each pendulum
		max += pendulum[i];
	}

	bead = new bool *[N + 1]; // if a bead weighing w can be measured?
	bead[0] = new bool[(max + 1) * (N + 1)];
	for (int i = 1; i < N + 1; i++)
		bead[i] = &bead[0][(max + 1) * i];

	for (int i = 0; i < N + 1; i++) // initialize bead
		for (int j = 0; j < max + 1; j++)
			bead[i][j] = false;

	bead[0][0] = true;
	for (int i = 1; i <= N; i++)
	{
		int w = pendulum[i];
		for (int j = 0; j <= max; j++)
		{
			if (bead[i - 1][j] == true)
			{
				bead[i][j] = true;
				bead[i][j + w] = true;

				if (j - w >= 0)
					bead[i][j - w] = true;
				else
					bead[i][w - j] = true;
			}
		}
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int w_bead;
		cin >> w_bead;

		if (w_bead <= max && bead[N][w_bead] == true)
			cout << 'Y';
		else
			cout << 'N';

		if (i < K - 1)
			cout << ' ';
	}

	return 0;
}