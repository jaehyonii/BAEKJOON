#include <iostream>
using namespace std;

int main(void) {
    int a, b, cnt = 0;

    cin >> a >> b;

    while (b > a) {
        if (b % 10 == 1) { //�� �� �ڸ��� 1
            b = b - 1;
            b = b / 10;
            cnt++;
        }
        else if (b % 2 == 0) { //¦���� ���
            b = b / 2;
            cnt++;
        }
        else { //�� ��쿡 �ش����� �ʴ� ��� ���� ���� �� ����
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