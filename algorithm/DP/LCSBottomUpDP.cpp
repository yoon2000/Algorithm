#include <iostream>
#include <string>
#define MAX_LENGTH 101
using namespace std;

int L[MAX_LENGTH][MAX_LENGTH];
int S[MAX_LENGTH][MAX_LENGTH];
string str1, str2;

void printLCS(int m, int n) {
    if(m == 0 || n == 0){
        return;
    }

    if(S[m][n] == 0){
        printLCS(m-1, n-1);
        cout << str1[m-1];
    }
    else if(S[m][n] == 1){
        printLCS(m, n-1);
    }
    else if(S[m][n] == 2){
        printLCS(m-1, n);
    }
}


int lengthLCS(int m, int n){

    for(int i=0; i<=m; i++){
        L[i][0] = 0;
    }

    for(int i=0; i<=n; i++){
        L[0][i] = 0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(str1[i-1] == str2[j-1]){
                L[i][j] = L[i-1][j-1]+1;
                S[i][j] = 0;
            } 
            else{
                L[i][j] = max(L[i][j-1], L[i-1][j]); 
                if(L[i][j] == L[i][j-1]){
                    S[i][j] = 1;
                }
                else{
                    S[i][j] = 2;
                }
            }
        }
    }
    return L[m][n];
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> str1 >> str2;

        int m = str1.length(), n = str2.length();

        cout << lengthLCS(m, n) << " ";
        printLCS(m, n);
        cout << endl;
    }
}