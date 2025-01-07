#include <iostream>
using namespace std;

void countUp(int n){
    if(n >= 0){
        countUp(n-1);
        cout << n << endl;
    }
}

void countDown(int n){
    if(n >= 0){
        cout << n << endl;
        countDown(n-1);
    }
}

int main(){
    countUp(4);
    cout << "--------------" << endl;
    countDown(4);
}