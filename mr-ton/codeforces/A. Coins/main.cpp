#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        // if (n%k%2 == 0 || (n%k+k)%2 == 0) cout << "YES\n"; // i don't know why. but it worked :()
        if (n%2==0 || (n >= k && (n-k)%2==0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
