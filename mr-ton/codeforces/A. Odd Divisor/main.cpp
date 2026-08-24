#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        long long n;
        cin >> n;
        // while (n % 2 == 0) {
        //     n /= 2;
        // }
        // if (n == 1) cout << "NO\n";
        // else cout << "YES\n";

        if ((n & (n-1)) == 0) cout << "NO\n";
        else cout << "YES\n";

        t--;
    }
    return 0;
}