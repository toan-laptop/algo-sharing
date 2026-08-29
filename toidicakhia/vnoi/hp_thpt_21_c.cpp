#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5;
ll a[N], n, k;
map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int target = 2 * k - a[i];
        if (mp[target]) {
            cout << mp[target] << " " << i;
            return 0;
        }

        mp[a[i]] = i;
    }

    cout << "0 0" << endl;

    return 0;
}
