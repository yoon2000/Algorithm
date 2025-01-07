#include <iostream>
#include <limits.h>
using namespace std;

int MCM(int p[], int i, int j){
    if(i == j){
        return 0;
    }

    int min_value = INT_MAX;
    int count;

    for(int k=i; k<j; k++){
        count = MCM(p, i, k) + MCM(p, k+1, j) + p[i]*p[k+1]*p[j+1];
        min_value = min(min_value, count);
    }
    return min_value;
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

        cout << MCM(p, 0, n-1) << endl;
    }
}
