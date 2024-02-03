#include <iostream>
#include <vector>
using namespace std;

vector <int>* graph; //undirected graph
bool* visited;
int* parent;

void DFS(int num) {
	visited[num] = 1;
	for (int i = 0; i < graph[num].size(); i++) {
		int child = graph[num][i];
		if (visited[child] == false) {
			parent[child] = num; //child's parent
			DFS(child); //visit child
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, a, b;

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
	
	DFS(1); //visit 1

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}

	delete[] graph;
	delete[] visited;

	return 0;
}