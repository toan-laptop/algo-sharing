#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int res = ((n+2-1)/2+m-1)/m*m;
    if (res <= n) cout << res;
    else cout << -1;
    return 0;
}
