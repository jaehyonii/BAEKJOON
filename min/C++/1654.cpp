#include <iostream>
#include <vector>
using namespace std;

int main(void) {

	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int k, n;
	long long num, max = -1;
	vector <int> v;

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> num;
		v.push_back(num);
		if (num > max) {
			max = num;
		}
	}

	long long int left = 1, mid, right = max, ans = -1;
	while (left <= right) {
		mid = (left + right) / 2;
		long long int temp = 0;

		for (int i = 0; i < k; i++) {
			temp += v[i] / mid;
		}

		if (temp >= n) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans;

	return 0;
}