#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> BaseMatrix;

vector<vector<int>> matrixMultiplication(vector<vector<int>> a, vector<vector<int>> b){
    int n = a.size();

    vector<vector<int>> v(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                v[i][j] += a[i][k] * b[k][j];
            }
            v[i][j] %= 10000;
        }
    }

    return v;
}

vector<vector<int>> fibPow(int n){ // 얘가 재귀적으로 돌아감
    vector<vector<int>> tmp;

    if(n == 1) return BaseMatrix;

    else if(n % 2 == 0){ // 짝수
        tmp = fibPow(n / 2);
        return matrixMultiplication(tmp, tmp);
    }

    else{ // 홀수
        tmp = fibPow((n-1) / 2);
        tmp = matrixMultiplication(tmp, tmp);
        return matrixMultiplication(tmp, BaseMatrix);
    }
}

int fastFib(int n){
    if(n == 0) return 0;
    else{
        vector<vector<int>> v = fibPow(n);
        return v[1][0] % 1000;
    }
}

int main(){
    vector<int> temp;
    temp.push_back(1); temp.push_back(1);
    BaseMatrix.push_back(temp);
    temp[1] = 0;
    BaseMatrix.push_back(temp);

    cout << fastFib(2147483647) << endl;
}