#include <iostream>

using namespace std;

int cnt1 = 0;
int cnt2 = 0;

int fibRecursive(int n)
{
	if (n == 1 || n == 2)
	{
		cnt1++;
		return 1;
	}
	else
		return (fibRecursive(n - 1) + fibRecursive(n - 2));
}

void fibDynamic(int n)
{
	int *arr = new int[n + 1];
	arr[1] = arr[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		cnt2++;
	}
}

int main()
{
	int n;

	cin >> n;

	fibRecursive(n);
	fibDynamic(n);

	cout << cnt1 << ' ' << cnt2;

	return 0;
}