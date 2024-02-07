#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, num, top;
	priority_queue <int, vector<int>, greater<int>> pq; //우선순위 큐 (오름차순)

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				top = pq.top();
				cout << top << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}

	return 0;
}