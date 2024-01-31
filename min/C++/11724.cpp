#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
	int n, m, start, end;
	int** arr;

	cin >> n >> m;

	arr = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		arr[i] = new int[n + 1];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			arr[i][j] = 0;
		}
	}

	//initialize
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		arr[start][end] = 1;
		arr[end][start] = 1;
	}

	int ans = 0;
	bool* visited;
	visited = new bool[n + 1];
	fill(visited, visited + n + 1, false);

	queue <int> q;

	for (int i = 1; i <= n; i++) {
		if (visited[i]==false) {
			visited[i] = true;
			q.push(i);
			while (!q.empty()) { //BFS
				int front = q.front();

				for (int j = 1; j <= n; j++) {
					if (arr[front][j] == 1 && visited[j] == false) {
						q.push(j);
						visited[j] = true;
					}
				}

				q.pop();
			}
			ans++;
		}
	}

	cout << ans;

	return 0;
}