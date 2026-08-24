#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> is_prime;
vector<bool> used;
vector<int> ring;

void sieve(int val) {
    is_prime.assign(val+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i*i <= val; ++i) {
        if (is_prime[i]) {
            for (int j = i*i; j <= val; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}

void backtrack(int i) {
    if (i == 2*n ) {
        if (is_prime[1 + ring[2*n-1]]) {
            for (int j = 0; j < 2*n; ++j) {
                cout << ring[j] << (j == 2*n-1 ? "" : " ");
            }
            cout << endl;
        }
        return;
    }
    for (int j = 2; j <= 2*n; ++j) {
        if (!used[j] && is_prime[ring[i-1] + j]) {
            used[j] = true;
            ring[i] = j;
            backtrack(i+1);
            used[j] = false;
        }
    }
}

int main() {
    cin >> n;
    sieve(4*n);
    used.assign(2*n+1, false);
    ring.resize(2*n);
    ring[0] = 1;
    used[1] = true;
    backtrack(1);
    return 0;
}