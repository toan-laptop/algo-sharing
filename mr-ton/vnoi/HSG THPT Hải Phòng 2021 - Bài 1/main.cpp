#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);
    for (char c : s) {
        if (isalpha(c)) cout << c;
    }
    return 0;
}
