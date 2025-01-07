#include <iostream>
#include <cmath>
using namespace std;

void Hanoi(int n, int a, int b, int c, unsigned long long k) {
    if (n > 0) {
        unsigned long long pow_value = pow(2, n - 1);
        if (k < pow_value) {
            Hanoi(n - 1, a, c, b, k);
        } else if (k > pow_value) {
            Hanoi(n - 1, b, a, c, k - pow_value);
        } else {
            cout << a << " " << c << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        unsigned long long k;
        cin >> n >> k;
        Hanoi(n, 1, 2, 3, k);
    }

    return 0;
}
