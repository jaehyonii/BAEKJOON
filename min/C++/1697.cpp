#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];

int main(void) {
	int n, k, length = 0, time = 0;
	queue <pair<int, int>> q;

	fill(visited, visited + 100001, false); //중복 제거를 위한 배열

	cin >> n >> k;

	q.push({ n,0 });
	visited[n] = true;

	while (!q.empty()) {
		length = q.front().first;
		time = q.front().second;

		if (length == k) { //수빈이가 동생을 찾은 경우
			break;
		}

		if (length*2 <= 100000 && visited[length * 2] == false) {
			q.push({ length * 2, time + 1 });
			visited[length * 2] = true;
		}

		if (length-1 >= 0 && visited[length - 1] == false) {
			q.push({ length - 1, time + 1 });
			visited[length - 1] = true;
		}

		if (length + 1 <= 100000 && visited[length + 1] == false) {
			q.push({ length + 1, time + 1 });
			visited[length + 1] = true;
		}

		q.pop();
	}

	cout << time;

	return 0;
}