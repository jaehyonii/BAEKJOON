#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int S = 0;
    int m, num;
    string str;

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> str;
        if (str == "all") {
            S = (1 << 21) - 1;
        }
        else if (str == "empty") {
            S = 0;
        }
        else {
            cin >> num;
            if (str == "add") {
                num = 1 << num;
                S = S | num;
            }
            else if (str == "remove") {
                num = ~(1 << num);
                S = S & num;
            }
            else if (str == "check") {
                if (S & (1 << num)) {
                    cout << 1 << "\n";
                }
                else {
                    cout << 0 << "\n";
                }
            }
            else if (str == "toggle") {
                if (S & (1 << num)) {
                    num = ~(1 << num);
                    S = S & num;
                }
                else {
                    num = 1 << num;
                    S = S | num;
                }
            }
        }
    }

    return 0;
}