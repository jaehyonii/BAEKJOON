#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int k, v, e, a, b;
	vector<int>* graph;
	bool* visited;
	int* color;

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> v >> e;
		graph = new vector<int>[v + 1];
		visited = new bool[v + 1];
		color = new int[v + 1];
		fill(visited, visited + v + 1, false); //0이면 방문 안 함, 1이면 방문함
		fill(color, color + v + 1, 0); //0이면 red, 1이면 blue

		for (int j = 0; j < e; j++) {
			cin >> a >> b;
			//간선 추가 (a와 b 연결)
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		queue <int> q;
		q.push(1);
		visited[1] = true;
		color[1] = 1;

		while (1) {
			while (!q.empty()) {
				int front = q.front();
				for (int j = 0; j < graph[front].size(); j++) {
					int num = graph[front][j];
					if (visited[num] == false) {
						q.push(num);
						visited[num] = true;
						if (color[front] == 0) {
							color[num] = 1;
						}
						else {
							color[num] = 0;
						}
					}
				}
				q.pop();
			}

			bool find = true;
			
			for (int i = 1; i <= v; i++) { //방문하지 않은 노드가 있는 경우
				if (visited[i] == false) {
					find = false;
					q.push(i);
					visited[i] = true;
					color[i] = 1;
					break;
				}
			}

			if (find) {
				break;
			}
		}

		bool bgraph = false;
		fill(visited, visited + v + 1, false);

		q.push(1);
		visited[1] = true;
		while (1) {
			while (!q.empty()) {
				int front = q.front();
				for (int j = 0; j < graph[front].size(); j++) {
					int num = graph[front][j];

					if (color[front] == color[num]) {
						bgraph = true;
						break;
					}

					if (visited[num] == false) {
						q.push(num);
						visited[num] = true;
					}
				}
				q.pop();
			}

			bool find = true;

			for (int i = 1; i <= v; i++) {
				if (visited[i] == false) {
					find = false;
					q.push(i);
					visited[i] = true;
				}
			}

			if (find) {
				break;
			}
		}

		if (bgraph) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}

		delete[] graph;
		delete[] visited;
		delete[] color;
	}

	return 0;
}