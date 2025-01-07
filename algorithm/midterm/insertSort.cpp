#include <iostream>
using namespace std;

void insertSort(int arr[], int n){

    for(int i=1; i<n; i++){

        // tmp 변수를 사용해서 swap 연산을 줄이는 개선도 가능함!
        
        for(int j = i; j > 0 && arr[j-1] > arr[j]; j--){
            swap(arr[j-1], arr[j]);
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[7] = {5, 11, 1, 3, 9, 8, 7};

    insertSort(arr, 7);
}