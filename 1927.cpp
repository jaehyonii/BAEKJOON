#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (num == 0)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(num);
	}

	return 0;
}