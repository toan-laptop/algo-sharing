#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = sqrt(c*a/b);
    int y = a/x;
    int z = c/x;
    cout << 4*(x+y+z);
    return 0;
}
