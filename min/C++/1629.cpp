#include <iostream>
using namespace std;

int main(void) {
    long long a, b, c;
    long long ans = 1;

    cin >> a >> b >> c;

    while (b > 0) {
        if (b % 2 != 0) {
            ans = ans * a % c;
        }
        a = a * a % c;

        b /= 2;
    }

    cout << ans;

    return 0;
}