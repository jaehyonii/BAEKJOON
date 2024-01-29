#include <iostream>
using namespace std;

int main(void) {
	int N, M, B;
	int** arr;
	int max = -1, min = 257;

	cin >> N >> M >> B;

	arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M]; //input
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j]; //input

			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
	}

	int result_t = 0, result_h = -1;
	while (max >= 0) {
		int temp_d = 0, temp_u = 0, temp_b = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//delete block
				if (arr[i][j] > max) {
					temp_d += arr[i][j] - max;
					temp_b += arr[i][j] - max;
				}
				//stack block
				else if (arr[i][j] < max) {
					temp_u += max - arr[i][j];
				}
			}
		}

		if (B + temp_b >= temp_u) {
			
			int temp_t = (temp_d) * 2 + (temp_u);

			if (result_h == -1) { //first answer
				result_t = temp_t;
				result_h = max;
			}
			else {
				if (temp_t < result_t) { //new answer
					result_t = temp_t;
					result_h = max;
				}
			}
		}
		max--;
	}

	cout << result_t << " " << result_h;

	for (int i = 0; i < N; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}