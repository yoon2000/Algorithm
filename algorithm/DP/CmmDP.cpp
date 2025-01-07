#include <iostream>
#include <limits.h>
using namespace std;

int m[101][101];
int p_index[101][101];

void order(int i, int j){
    if(i == j){
        cout << "M" << i+1;
    }
    else{
        int k = p_index[i][j];
        cout << "(";
        order(i, k);
        order(k+1, j);
        cout << ")";
    }
}

int MCM(int p[], int i, int j){
    int n = j - i + 1;

    for(int i=0; i<n; i++){
        m[i][i] = 0;
    }

    for(int l=2; l<=n; l++){
        for(int i=0; i<n-l+1; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                int count = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                m[i][j] = min(m[i][j], count);
                if(m[i][j] == count){
                    p_index[i][j] = k;
                }
            }
        }
    }

    return m[0][n-1];
}


int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int p[n+1];
        for(int i=0; i<=n; i++){
            cin >> p[i];
        }

        int answer = MCM(p, 0, n-1);
        order(0, n-1);
        cout << endl;
        cout << answer << endl;
    }
}
