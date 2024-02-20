#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> *graph;
int *dist;
bool *visited;
int INF = 2147483647;
int N;

void Dijkstra(int start)
{
	queue<int> q;

	q.push(start);
	dist[start] = 0;
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		for (auto it = graph[cur].begin(); it != graph[cur].end(); it++)
		{
			if (dist[cur] + it->second < dist[it->first])
				dist[it->first] = dist[cur] + it->second;
		}

		int min_dist = INF, min_node = cur;
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == false && dist[i] < min_dist)
			{
				min_node = i;
				min_dist = dist[i];
			}
		}

		if (min_node != cur)
		{
			q.push(min_node);
			visited[min_node] = true;
		}

		q.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M;
	cin >> N >> M;
	graph = new vector<pair<int, int>>[N + 1];
	dist = new int[N + 1];
	visited = new bool[N + 1];

	for (int i = 0; i < M; i++)
	{
		int s, e, d;
		cin >> s >> e >> d;
		graph[s].push_back(make_pair(e, d));
	}

	for (int i = 0; i <= N; i++)
	{
		dist[i] = INF;
		visited[i] = false;
	}

	int start, end;
	cin >> start >> end;
	Dijkstra(start);
	cout << dist[end];

	delete[] graph;
	delete[] dist;
	delete[] visited;

	return 0;
}