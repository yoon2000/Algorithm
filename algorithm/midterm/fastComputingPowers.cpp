#include <iostream>
using namespace std;

double fastPower(double x, int n){
    if(n == 0) return 1;

    else if(n % 2 == 0){ // 짝수
        double tmp = fastPower(x, n/2);
        return tmp * tmp;
    }

    else{ // 홀수
        double tmp = fastPower(x, (n - 1) / 2);
        return x * tmp * tmp;
    }
}

int main(){
    double answer = fastPower(3.0, 3);
    cout << answer << endl;
}