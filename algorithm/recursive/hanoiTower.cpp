#include <iostream>
using namespace std;

int global_counter = 0;

void Hanoi(int n, int a, int b, int c, unsigned long long int k){
    if(n > 0){
        unsigned long long int pow_value = 1ULL << (n - 1);
        if(k < global_counter + pow_value){
            Hanoi(n-1, a, c, b, k);
            return;
        }

        global_counter += pow_value;
        if(k == global_counter){
            cout << a << " " << c << endl;
            return;
        }

        Hanoi(n-1, b, a, c, k);
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        global_counter = 0;
        int n;
        unsigned long long int k;
        cin >> n >> k;

        Hanoi(n, 1, 2, 3, k);
    }
}