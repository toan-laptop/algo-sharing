#include <bits/stdc++.h>
using namespace std;

string s, res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);

    for (char c: s) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            res += c;
    }

    cout << res;
    return 0;
}
