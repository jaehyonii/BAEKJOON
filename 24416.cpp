#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int **S = new int *[N];
	for (int i = 0; i < N; i++)
		int S[i] = new int[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> S[i][j];

	for (int i = 0; i < N; i++)
		delete S[i];
	delete S;

	return 0;
}