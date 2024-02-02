#include <iostream>
using namespace std;

int main(void) {
    int a, b, cnt = 0;

    cin >> a >> b;

    while (b > a) {
        if (b % 10 == 1) { //맨 끝 자리가 1
            b = b - 1;
            b = b / 10;
            cnt++;
        }
        else if (b % 2 == 0) { //짝수인 경우
            b = b / 2;
            cnt++;
        }
        else { //두 경우에 해당하지 않는 경우 수를 만들 수 없음
            break;
        }
    }

    if (b == a) {
        cnt++;
        cout << cnt;
    }
    else {
        cout << -1;
    }

    return 0;
}