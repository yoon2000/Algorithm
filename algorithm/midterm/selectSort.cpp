#include <iostream>
using namespace std;

void selectSort(int arr[], int n){

    for(int i=0; i<n; i++){
        int jmin = i;

        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[jmin]){
                jmin = j;
            }
        }

        if(jmin != i){
            swap(arr[i], arr[jmin]);
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[7] = {5, 11, 1, 3, 9, 8, 7};

    selectSort(arr, 7);
}