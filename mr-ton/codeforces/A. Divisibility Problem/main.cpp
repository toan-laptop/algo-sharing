#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int a, b;
        cin >> a >> b;
        cout << (b - a % b) % b << endl;
        t--;
    }
    return 0;
}
