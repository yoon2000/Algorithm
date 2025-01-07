#include <iostream>
#include <string>
#include <vector>
#define MAX_SIZE 101
using namespace std;

string str1, str2;
int memo[MAX_SIZE][MAX_SIZE];

int LCS(int m, int n){
    if( m == 0 || n == 0){
        return 0;
    }

    if(memo[m][n] != -1){
        return memo[m][n];
    }

    if( m > 0 && n > 0 && str1[m-1] == str2[n-1]){
        memo[m][n] = LCS(m-1, n-1) + 1;
    }
    else{
        memo[m][n] = max(LCS(m-1, n), LCS(m, n-1));
    }
    return memo[m][n];
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> str1 >> str2;

        //init
        for(int i=0; i<MAX_SIZE; i++){
            for(int j=0; j<MAX_SIZE; j++){
                memo[i][j] = -1;
            }
        }

        cout << LCS(str1.length(), str2.length()) << endl;
    }
}