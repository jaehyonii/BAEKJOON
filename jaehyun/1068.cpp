#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arr[50]; // parent information
	int N;
	cin >> N;
	vector<int> *tree = new vector<int>[N];

	int parent;
	int root;
	// make tree
	for (int i = 0; i < N; i++)
	{
		cin >> parent;
		arr[i] = parent;
		if (parent == -1)
		{
			root = i;
			continue;
		}
		tree[parent].push_back(i);
	}

	int delNode;
	cin >> delNode; // get deleted node
	int num = 0;	// the number of leaves
	if (delNode != root)
	{
		parent = arr[delNode];
		for (auto it = tree[parent].begin(); it != tree[parent].end(); it++)
		{
			if (*it == delNode)
			{
				tree[parent].erase(it);
				break;
			}
		}

		queue<int> Queue;
		Queue.push(root);
		while (!Queue.empty())
		{
			int front = Queue.front();

			if (tree[front].size() == 0)
			{
				num++;
			}
			else
			{
				for (auto it : tree[front])
				{
					Queue.push(it);
				}
			}

			Queue.pop();
		}
	}

	cout << num;
	delete[] tree;

	return 0;
}