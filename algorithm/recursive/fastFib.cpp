#include <iostream>
#include <vector>
using namespace std;

// 하나씩 곱하지 말고 fastcomputingPower 방식을 적용해볼것

vector<vector<int>> matrix_mult(const vector<vector<int>>& A, const vector<vector<int>>& B, int mod) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }

    return result;
}

vector<vector<int>> fast_fib(const vector<vector<int>>& base, long long exp, int mod){
    int n = base.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    // 대각선 다 1로 채워주기 == 곱해도 자기자신이 나오는 행렬!
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }

    vector<vector<int>> A = base;

    while (exp > 0) {
        // exp 가 홀수일떄 base 하나만 따로 곱한다
        if (exp % 2 == 1) {
            result = matrix_mult(result, A, mod);
        }
        A = matrix_mult(A, A, mod);
        exp /= 2;
    }

    return result;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(n == 0){
            cout << 0 << endl;
            continue;
        }

        vector<vector<int>> base = {{1, 1}, {1, 0}};
        vector<vector<int>> result = fast_fib(base, n - 1, 10000);

        cout << result[0][0] % 1000 << endl;
    }
}