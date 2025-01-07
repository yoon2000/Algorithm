#include <iostream>
#include <string>
using namespace std;

void baseConversion(int n, int base){
    string baseTable = "0123456789abcdef";
    if(n >= base){
        baseConversion(n/base, base);
    }
    cout << baseTable[n%base];
}

int main(){
    int num = 1234567;
    baseConversion(num, 16);
    cout << endl;
}