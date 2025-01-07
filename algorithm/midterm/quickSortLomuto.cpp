#include <iostream>
using namespace std;

int arr[10] = { 5, 6, 9, 4, 0, 2, 1, 7, 3, 8 };

int partition(int low, int high){
    int pivot = arr[low];
    int j = low;

    for(int i = low+1; i<10; i++){
        if(arr[i] < pivot){
            j++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[low], arr[j]);

    return j;
}

void quickSort(int low, int high){
    if(high > low){
        int pivotPos = partition(low, high);
        quickSort(low, pivotPos-1);
        quickSort(pivotPos+1, high);
    }
}

int main(){
    quickSort(0 , 9);

    // 정렬된 데이터 출력
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}