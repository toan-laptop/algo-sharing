#include <bits/stdc++.h>

using namespace std;

vector<bool> prime_nums(31623, true);
vector<int> prime_nums2;

void sieve() {
    prime_nums[0] = prime_nums[1] = false;
    for (int i = 2; i <= 31622; ++i) {
        if (prime_nums[i]) {
            prime_nums2.push_back(i);
            for (int j = i*i; j <= 31622; j+=i) {
                prime_nums[j] = false;
            }
        }
    }
}

bool isPrime(int n) {
    if (n <= 31622) return prime_nums[n];
    for (int x : prime_nums2 ) {
        if (x*x > n) return true;
        if (n % x == 0) return false;
    }
    return true;
}

bool isSuperPrime(int n) {
    if (!isPrime(n)) return false;

    bool c = false;
    for (int i = 1; i < 10; i+=2) {
        if (isPrime(n*10+i)) {
            c = true;
            break;
        }
    }
    if (!c) return false;

    while (n/10 > 0) {
        if (!isPrime(n/10)) {
            return false;
        }
        n/=10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n;
    cin >> n;
    vector<int> super_primes(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        super_primes[i+1] = isSuperPrime(x) + super_primes[i];
    }

    int t;
    cin >> t;
    for (int i = 0; i < t ; ++i) {
        int l, r;
        cin >> l >> r;
        cout << super_primes[r] - super_primes[l-1] << "\n";
    }
    return 0;
}
