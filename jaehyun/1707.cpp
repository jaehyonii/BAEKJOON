#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool BFS(int V, int E)
{
	vector<int> *graph = new vector<int>[V + 1];
	int *color = new int[V + 1];   // color 1 or -1
	fill(color, color + V + 1, 0); // color initialization

	// make graph
	for (int i = 0; i < E; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// BFS
	queue<int> Queue;
	for (int i = 1; i <= V; i++)
	{
		if (color[i] != 0)
			continue;

		color[i] = 1;
		Queue.push(i);
		while (!Queue.empty())
		{
			int front = Queue.front();

			for (auto it = graph[front].begin(); it != graph[front].end(); it++)
			{
				if (color[*it] == 0)
				{
					color[*it] = -color[front];
					Queue.push(*it);
				}
				else if (color[*it] == color[front])
					return false;
			}

			Queue.pop();
		}
	}

	delete[] graph;
	delete[] color;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int V, E;
		cin >> V >> E;

		if (BFS(V, E))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}