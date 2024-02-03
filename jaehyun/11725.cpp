#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int x, y;

	cin >> N;

	vector<int> *graph = new vector<int>[N + 1];

	for (int i = 1; i < N; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int *parent = new int[N + 1];
	bool *visited = new bool[N + 1];
	fill(visited + 1, visited + N + 1, false);

	queue<int> Queue;
	Queue.push(1);
	visited[1] = true;
	while (!Queue.empty())
	{
		int node = Queue.front();

		for (auto it = graph[node].begin(); it != graph[node].end(); it++)
		{
			if (visited[*it] == false)
			{
				parent[*it] = node;
				Queue.push(*it);
				visited[*it] = true;
			}
		}

		Queue.pop();
	}

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';

	delete[] graph;
	delete[] parent;
	delete[] visited;

	return 0;
}