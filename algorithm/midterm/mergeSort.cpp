#include <iostream>
#define MAX_SIZE 100
using namespace std;

int arr[14] = { 12,15,20,25,32,35,40,45,31,26,12,8,7,3 };
int n = 14;

void merge(int left, int mid, int right){
    int tmp[MAX_SIZE];

    int i, j, k;

    for(i=left; i<=right; i++){
        tmp[i] = arr[i];
    }

    i = k = left;
    j = mid+1;

    while(i <= mid && j <= right){
        if(tmp[i] <= tmp[j]){
            arr[k++] = tmp[i++];
        }
        else{
            arr[k++] = tmp[j++];
        }
    }

    while(i <= mid) arr[k++] = tmp[i++];
    while(j <= right) arr[k++] = tmp[j++];
}

void mergeSort(int left, int right){

    if(left == right) return;

    int mid = (left+right) / 2;
    mergeSort(left, mid);
    mergeSort(mid+1, right);
    merge(left, mid, right);
}

int main(){
   mergeSort(0, n-1);
   //정렬된 배열 출력하기
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}