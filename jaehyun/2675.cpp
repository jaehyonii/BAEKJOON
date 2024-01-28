#include <iostream>

using namespace std;

int main()
{
	int T, R;
	char arr[21];

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> R >> arr;

		for (int j = 0; arr[j] != 0; j++)
		{
			for (int k = 0; k < R; k++)
				cout << arr[j];
		}
		cout << endl;
	}

	return 0;
}