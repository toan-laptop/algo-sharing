#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i].first;
        nums[i].second = i+1;
    }

    sort(nums.begin(), nums.end());
    int l = 0, r = n-1;
    k *= 2;
    int c = 0;
    while (l < r) {
        if (nums[l].first + nums[r].first < k) {
            ++l;
        } else if (nums[l].first + nums[r].first > k) {
            --r;
        } else {
            c = 1;
            cout << nums[l].second << " " << nums[r].second;
            break;
        }
    }
    if (!c) cout << "0 0";
    
    return 0;
}
