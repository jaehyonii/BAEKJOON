#include <iostream>

using namespace std;

int find(int *parent, int x)
{
	if (parent[x] == x) // 배열 인덱스와 값이 같다면 해당 값 리턴
		return x;
	return parent[x] = find(parent, parent[x]); // 배열의 값을 인덱스로 갖는 값 리턴
}

void merge(int *parent, int x, int y)
{
	x = find(parent, x);
	y = find(parent, y); // 각각 find연산을 통해 루트 노드를 가짐
	if (x == y)
		return;	   // x와 y가 같다면 이미 연결되어있는 것
	parent[y] = x; // 배열의 y인덱스에 x값을 저장
}

bool isUnion(int *parent, int x, int y)
{ // 두 노드가 연결되어있는지 판별하는 함수
	x = find(parent, x);
	y = find(parent, y);
	if (x == y)
		return true;
	return false;
}

int main()
{
	int N, M;

	cin >> N >> M;

	int *parent = new int[N + 1]; // root of graph
	for (int i = 1; i <= N; i++)
		parent[i] = i; // initialize

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		merge(parent, x, y);
	}
	for (int i = 1; i <= N; i++)
	{
		find(parent, i);
	}

	int cnt = 0;				 // the number of different graphs
	for (int i = 1; i <= N; i++) // counting
	{
		int j;
		for (j = 1; j < i; j++)
		{
			if (parent[i] == parent[j])
				break;
		}
		if (i == j)
			cnt++;
	}

	cout << cnt;

	delete[] parent;

	return 0;
}