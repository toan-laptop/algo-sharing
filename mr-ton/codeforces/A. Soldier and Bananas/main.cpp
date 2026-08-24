#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n, w;
    cin >> k >> n >> w;
    int t = k * (1+w)*w/2 - n;
    if (t > 0) cout << t;
    else cout << 0;
    return 0;
}
