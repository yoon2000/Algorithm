#include <iostream>
using namespace std;

int sum(int a[], int n){
    if(n == 0){
        return 0;
    }
    else{
        return a[n-1] + sum(a, n-1);
    }
}

int main(){
    int a[5] = { 3, 6, 5, 2, 4};
    cout << sum(a, 5) << endl;
}