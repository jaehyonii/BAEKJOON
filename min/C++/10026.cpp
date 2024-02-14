#include <iostream>
#include <queue>
#include <string>
using namespace std;

int** arr; //���� ǥ��
bool** visited; //�湮 ǥ��
int n, ans1, ans2;
int dist_x[4] = {-1, 1, 0, 0};
int dist_y[4] = {0, 0, -1, 1};

//���� ������ �ƴ� ����� ���� ��
void BFS(int x, int y) {
	int target = arr[x][y];
	queue <pair<int, int>> q;
	
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		int tmp_x = q.front().first;
		int tmp_y = q.front().second;

		for (int i = 0; i < 4; i++) {
			int new_x = tmp_x + dist_x[i];
			int new_y = tmp_y + dist_y[i];

			//���� ������ ���� �湮
			if ((new_x >= 0) && (new_x < n) && (new_y >= 0) && (new_y < n)) {
				if (visited[new_x][new_y] == false && arr[new_x][new_y] == target) {
					q.push({ new_x, new_y });
					visited[new_x][new_y] = true;
				}
			}
		}

		q.pop();
	}
}

//���� ������ ����� ���� ��
void BFS2(int x, int y) {
	int target = arr[x][y];
	queue <pair<int, int>> q;

	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		int tmp_x = q.front().first;
		int tmp_y = q.front().second;

		for (int i = 0; i < 4; i++) {
			int new_x = tmp_x + dist_x[i];
			int new_y = tmp_y + dist_y[i];

			if ((new_x >= 0) && (new_x < n) && (new_y >= 0) && (new_y < n)) {
				if (visited[new_x][new_y] == false) {
					if (target == 'B') { //target�� blue�� ���
						if (arr[new_x][new_y] == 'B') { //arr[new_x][new_y]�� blue�� ��쿡 �湮
							q.push({ new_x, new_y });
							visited[new_x][new_y] = true;
						}
					}
					else { //target�� red or green�� ���
						if (arr[new_x][new_y] == 'R' || arr[new_x][new_y] == 'G') { //arr[new_x][new_y]�� red or green�� ��쿡 �湮
							q.push({ new_x, new_y });
							visited[new_x][new_y] = true;
						}
					}
				}
			}
		}

		q.pop();
	}
}

int main(void) {
	cin >> n;
	arr = new int* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		visited[i] = new bool[n];
	}

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false) {
				BFS(i, j);
				ans1++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false) {
				BFS2(i, j);
				ans2++;
			}
		}
	}

	cout << ans1 << " " << ans2;

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
		delete[] visited[i];
	}
	delete[] arr;
	delete[] visited;

	return 0;
}