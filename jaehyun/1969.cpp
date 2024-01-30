#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int hd = 0; // hamming distance

	cin >> n >> m;

	char **dna = new char *[n];
	for (int i = 0; i < n; i++)
	{
		dna[i] = new char[m + 1];
		cin >> dna[i];
	}

	char *res = new char[m + 1]; // result
	res[m] = '\0';
	for (int i = 0; i < m; i++)
	{
		int A = 0, T = 0, G = 0, C = 0;
		for (int j = 0; j < n; j++)
		{
			switch (dna[j][i])
			{
			case 'A':
				A++;
				break;
			case 'T':
				T++;
				break;
			case 'G':
				G++;
				break;
			case 'C':
				C++;
				break;
			}
		}

		int d = A;
		char ch = 'A';
		if (d < C)
		{
			d = C;
			ch = 'C';
		}
		if (d < G)
		{
			d = G;
			ch = 'G';
		}
		if (d < T)
		{
			d = T;
			ch = 'T';
		}

		res[i] = ch;
		hd += (n - d);
	}

	cout << res << '\n'
		 << hd;

	for (int i = 0; i < n; i++)
	{
		delete[] dna[i];
	}
	delete[] dna;
	delete[] res;

	return 0;
}