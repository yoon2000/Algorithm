#include <iostream>
using namespace std;

double p(double x, int n){
    if(n == 0) return 1;
    else{
        return x * p(x, n-1);
    }
}

int main(){
    cout << p(2.0, 3) << endl;
}