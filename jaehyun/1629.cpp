#include <iostream>

using namespace std;

int main()
{
	long long a, b, c;

	cin >> a >> b >> c;

	long long res = 1;

	while (b > 0)
	{
		if (b % 2 != 0)
			res = res * a % c;

		a = a * a % c;

		b /= 2;
	}

	cout << res;

	return 0;
}