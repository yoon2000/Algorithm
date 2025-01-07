#include <iostream>
using namespace std;

int fast_pow(int x, int n){
    int tmp;

    if(n == 0) return 1;

    else if(n % 2){
        tmp = fast_pow(x, (n-1)/2);
        tmp %= 10000;
        
        tmp *= tmp;
        tmp %= 10000;

        return (x * tmp) % 10000;
    }
    else{
        tmp = fast_pow(x, n/2);
        tmp %= 10000;

        tmp *= tmp;
        tmp %= 10000;

        return (tmp) % 10000;
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b, answer;

        cin >> a >> b;

        cout << fast_pow(a, b) % 1000 << endl;
    }
}