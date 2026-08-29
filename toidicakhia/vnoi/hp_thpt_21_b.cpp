#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
bool nt[N];
int f[100005], n, x, a, b;
vector<int> snt;

void sang() {
    memset(nt, true, sizeof(nt));

    nt[0] = nt[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (nt[i]) for (int j = i * i; j < N; j += i) nt[j] = false;
    }

    for (int i = 2; i < N; i++) if (nt[i]) snt.emplace_back(i);
}

bool isPrime(int number) {
    if (number < N) return nt[number];

    for (int i: snt) {
        if (i * i > number)
            break;

        if (number % i == 0)
            return false;
    }

    return true;
}

bool check(int number) {
    bool ok = false;

    for (int i = 1; i <= 9; i++) {
        if (isPrime(number * 10 + i))
            ok = true;
    }

    if (!ok) return false;

    while (number > 0) {
        if (!isPrime(number))
            return false;

        number /= 10;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sang();

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x;
        f[i] = f[i - 1] + check(x);
    }

    cin >> n;

    while (n--) {
        cin >> a >> b;
        cout << f[b] - f[a - 1] << endl;
    }

    return 0;
}