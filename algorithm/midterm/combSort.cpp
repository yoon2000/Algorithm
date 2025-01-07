#include <iostream>
using namespace std;

void combSort(int arr[], int n){

    int gap = n;
    double shrink = 1.3;
    bool sorted = false;

    while(!sorted){
        gap = gap/shrink;
        if(gap <= 1){
            gap = 1;
            sorted = true;
        }

        int i = 0;
        while(i + gap < n){
            if(arr[i] > arr[i+gap]){
                swap(arr[i], arr[i+gap]);
                sorted = false;
            }
            i += gap;
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[7] = {5, 11, 1, 3, 9, 8, 7};

    combSort(arr, 7);
}