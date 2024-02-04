#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	pair<int, int> p;			 // p. first : location	p.second : seconds
	queue<pair<int, int>> Queue; // BFS
	bool visited[100001];		 // to avoid memory overflow
	fill(visited, visited + 100001, false);

	p = make_pair(N, 0);
	Queue.push(p);
	while (!Queue.empty())
	{
		p = Queue.front();
		if (p.first == K)
			break;

		if (p.first - 1 >= 0 && p.first - 1 <= 100000 && visited[p.first - 1] == false)
		{
			Queue.push(make_pair(p.first - 1, p.second + 1));
			visited[p.first - 1] = true;
		}
		if (p.first + 1 >= 0 && p.first + 1 <= 100000 && visited[p.first + 1] == false)
		{
			Queue.push(make_pair(p.first + 1, p.second + 1));
			visited[p.first + 1] = true;
		}
		if (p.first * 2 >= 0 && p.first * 2 <= 100000 && visited[p.first * 2] == false)
		{
			Queue.push(make_pair(p.first * 2, p.second + 1));
			visited[p.first * 2] = true;
		}

		Queue.pop();
	}

	cout << p.second;

	return 0;
}