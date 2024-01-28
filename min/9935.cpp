#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    string s, p;
    int len;
    stack <char> st;

    cin >> s >> p;
    len = p.length();

    for (int i = 0; i < s.length(); i++) {
        st.push(s[i]);
        if (st.size() >= len && s[i] == p[len - 1]) {
            stack <char> temp;
            char top;
            for (int j = len - 1; j >= 0; j--) {
                top = st.top();
                if (top == p[j]) {
                    temp.push(top);
                    st.pop();
                }
                else {
                    while (!temp.empty()) {
                        top = temp.top();
                        st.push(top);
                        temp.pop();
                    }
                    break;
                }
            }
        }
    }

    stack <char> temp;

    if (!st.empty()) {
        while (!st.empty()) {
            char top = st.top();
            temp.push(top);
            st.pop();
        }

        //print result
        while (!temp.empty()) {
            char top = temp.top();
            cout << top;
            temp.pop();
        }
    }
    else {
        cout << "FRULA"; //no string
    }

    return 0;
}