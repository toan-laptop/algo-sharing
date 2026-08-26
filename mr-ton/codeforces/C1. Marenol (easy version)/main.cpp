#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    int n;
    char c;
    while (T--) {
        cin >> n;
        int a = 0;
        int b = 0;
        for (int i = 0; i < n; ++i) {
            cin >> c;
            if (c == '1') {
                if (i%2 == 0) ++a;
                else ++b;
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> c;
            if (c == '1') {
                if (i%2 == 0) --a;
                else --b;
            }
        }
        if (a == b && b == 0) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}
