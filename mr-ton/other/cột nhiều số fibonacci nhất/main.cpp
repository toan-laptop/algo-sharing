// link hackerrank: https://www.hackerrank.com/tim-cot-co-nhieu-so-fibonacci-nhat
#include <iostream>
#include <cmath>

bool isPerfectSquare(long long n) {
    long long t = sqrt(n);
    return n == t*t;
}

bool isFib(long long n) {
    return isPerfectSquare(5*n*n+4) || isPerfectSquare(5*n*n-4);
}

int main() {
    using namespace std;

    int T;
    cin >> T;

    while (T != 0) {
        int row, col;
        cin >> row >> col;

        long long db[500][2] = {0};
        long long matrix[row][col];
        int ind = 0, c = 0;
        long long total = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j ++) {
                cin >> matrix[i][j];
                if (isFib(matrix[i][j])) {
                    db[j][0]++;
                    db[j][1] += matrix[i][j];
                }
                if (i == row-1) {
                    if (c < db[j][0]) {
                        ind = j;
                        c = db[j][0];
                        total = db[j][1];
                    } else if (c == db [j][0]) {
                        if (total < db[j][1]) {
                            ind = j;
                            total = db[j][1];
                        }
                    }
                }
            }
        }

        cout << ind+1 << endl;
        for (int i = 0; i < row; i++) {
            if (isFib(matrix[i][ind])) {
                cout << matrix[i][ind] << " ";
            }
        }
        cout << endl;

        T--;
    }

    return 0;
}