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
	fill(leaf, leaf + n, 1); //leaf ����� 1, �ƴ϶�� 0

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == -1) {
			root = i; //root ���
		}
		else {
			parent[i] = num; //i�� �θ���� num
			tree[num].push_back(i);
		}

		leaf[num] = 0; //num�� leaf ��尡 �ƴ�
	}

	cin >> del; //������ ���
	if (del == root) {
		cout << 0;
	}
	else {
		q.push(del);
		int p = parent[del]; //�����Ϸ��� ����� �θ� ���

		if (tree[p].size() == 1) { //�θ� ����� �ڽ��� �ϳ���� �ش� �θ� ���� leaf ��尡 ��
			leaf[p] = 1;
		}

		while (!q.empty()) {
			int front = q.front();
			for (int i = 0; i < tree[front].size(); i++) {
				q.push(tree[front][i]);
			}
			leaf[front] = 0; //front�� leaf ��尡 �ƴ�
			q.pop();
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (leaf[i] == 1) { //leaf[i]�� 1�̸� leaf �����
				ans++;
			}
		}

		cout << ans;
	}

	return 0;
}