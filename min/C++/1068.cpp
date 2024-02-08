#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
	int n, num, root, del;
	vector <int>* tree;
	int* parent;
	int* leaf;
	queue <int> q;

	cin >> n;
	tree = new vector <int>[n];
	parent = new int[n];
	leaf = new int[n];
	fill(leaf, leaf + n, 1); //leaf 노드라면 1, 아니라면 0

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == -1) {
			root = i; //root 노드
		}
		else {
			parent[i] = num; //i의 부모노드는 num
			tree[num].push_back(i);
		}

		leaf[num] = 0; //num은 leaf 노드가 아님
	}

	cin >> del; //삭제할 노드
	if (del == root) {
		cout << 0;
	}
	else {
		q.push(del);
		int p = parent[del]; //삭제하려는 노드의 부모 노드

		if (tree[p].size() == 1) { //부모 노드의 자식이 하나라면 해당 부모 노드는 leaf 노드가 됨
			leaf[p] = 1;
		}

		while (!q.empty()) {
			int front = q.front();
			for (int i = 0; i < tree[front].size(); i++) {
				q.push(tree[front][i]);
			}
			leaf[front] = 0; //front는 leaf 노드가 아님
			q.pop();
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (leaf[i] == 1) { //leaf[i]가 1이면 leaf 노드임
				ans++;
			}
		}

		cout << ans;
	}

	return 0;
}