#include <bits/stdc++.h>

using namespace std;

vector<bool> prime_nums(31622, true);

void sieve(int n) {
    prime_nums[0] = false;
    prime_nums[1] = true;
    for (int i = 2; i*i <= n; ++i) {
        if (prime_nums[i]) {
            for (int j = i*i; j <= n; j+=i) {
                prime_nums[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    sieve(n);
    for (int i = 2; i*i <= n; i++) {
        if (prime_nums[i]) cout << i*i << " ";
    }
    return 0;
}
