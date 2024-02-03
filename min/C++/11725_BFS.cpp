#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, a, b;
	vector <int>* graph; //undirected graph
	bool* visited;
	queue <int> q;
	int* parent;

	cin >> n;
	graph = new vector <int>[n + 1];

	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		graph[a].push_back(b); //add edge
		graph[b].push_back(a); //add edge
	}

	visited = new bool[n + 1]; //visit or not for BFS
	parent = new int[n + 1]; //the node's parent
	fill(visited, visited + n + 1, false);

	q.push(1);
	visited[1] = true; //visited 1

	//BFS
	while (!q.empty()) {
		int front = q.front();
		for (int i = 0; i < graph[front].size(); i++) {
			int num = graph[front][i];
			if (visited[num] == false) { //not visited
				q.push(num);
				visited[num] = true;
				parent[num] = front; //num's parent is front
			}
		}
		q.pop();
	}

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}

	delete[] graph;
	delete[] visited;

	return 0;
}