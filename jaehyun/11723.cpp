#include <iostream>

using namespace std;

int S = 0;

void add(int x)
{
	S = S | 1 << x;
}
void remove(int x)
{
	S = S & ~(1 << x);
}
void check(int x)
{
	if (S & 1 << x)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}
void toggle(int x)
{
	S = S ^ 1 << x;
}
void all()
{
	S = 0b111111111111111111111;
}
void empty()
{
	S = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string cmd;
		int x;
		cin >> cmd;

		if (cmd == "add")
		{
			cin >> x;
			add(x);
		}
		else if (cmd == "remove")
		{
			cin >> x;
			remove(x);
		}
		else if (cmd == "check")
		{
			cin >> x;
			check(x);
		}
		else if (cmd == "toggle")
		{
			cin >> x;
			toggle(x);
		}
		else if (cmd == "all")
			all();
		else if (cmd == "empty")
			empty();
	}

	return 0;
}