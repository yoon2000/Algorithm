#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}

int interativeGcd(int a, int b){
    while(b > 0){
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main(){
    int answer = gcd(1071, 1029);
    cout << answer << endl;

    answer = interativeGcd(1071, 1029);
    cout << answer << endl;
}