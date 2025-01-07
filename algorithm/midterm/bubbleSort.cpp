#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=1; i<n; i++){

        // for loop 돌때 만약 swap이 되지 않았다면 정렬된거라서 처리해주면 조금 개선 가능

        for(int j=1; j <= n-i; j++){
            if(arr[j-1] > arr[j]){
                swap(arr[j-1], arr[j]);
            }
        }
        cout << "[i : " << i <<  "]" << endl;
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[7] = {5, 11, 1, 3, 9, 8, 7};

    bubbleSort(arr, 7);
}