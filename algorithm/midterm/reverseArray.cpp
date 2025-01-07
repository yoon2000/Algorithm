#include <iostream>
using namespace std;

void reverseArrray(int a[], int i, int j){
    if(i >= j) return;
    else{
        swap(a[i], a[j]);
        reverseArrray(a, i+1, j-1);
    }
}

int main(){
    int a[10] = {5, 7, 1, 3, 4, 9, 2, 0, 8, 6};
    reverseArrray(a, 0, 9);

    for(int i=0; i<10; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}