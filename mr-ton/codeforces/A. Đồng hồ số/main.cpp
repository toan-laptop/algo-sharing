#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2) cout << '7';
    else cout << "1";
    cout << string(n/2-1, '1');
    return 0;
}