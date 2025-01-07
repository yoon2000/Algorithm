#include <iostream>
using namespace std;

void shellSort(int arr[], int n){

    double shrink = 2;
    int gap = n / shrink;

    while(gap > 0){
        for(int i = gap; i < n; i++){
            int tmp = arr[i];
            for(int j = i; (j-gap >= 0) && (arr[j-gap] > tmp); j -= gap){
                arr[j] = arr[j-gap];
                arr[j-gap] = tmp;
            }
        }
        gap /= shrink;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[7] = {5, 11, 1, 3, 9, 8, 7};

    shellSort(arr, 7);
}