#include <iostream>
using namespace std;

int* dp;
int* before;

int main(void) {
	int n;

	cin >> n;
	dp = new int[n + 1];
	before = new int[n + 1];
	
	dp[1] = 0;
	before[1] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1; //1을 빼는 연산
		before[i] = i - 1;

		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) { //3으로 나누는 연산
			dp[i] = dp[i / 3] + 1;
			before[i] = i / 3;
		}

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) { //2으로 나누는 연산
			dp[i] = dp[i / 2] + 1;
			before[i] = i / 2;
		}
	}

	cout << dp[n] << endl;
	
	int cur = n;
	while (cur != 0) {
		cout << cur << " ";
		cur = before[cur];
	}

	delete[] dp;
	delete[] before;

	return 0;
}