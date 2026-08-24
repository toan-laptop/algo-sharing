#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, s;
    cin >> a >> b >> s;
    if ((abs(a) + abs(b) - s) % 2 == 0 && abs(a) + abs(b) <= s) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}