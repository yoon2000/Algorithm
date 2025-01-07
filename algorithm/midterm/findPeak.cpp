#include <iostream>
using namespace std;

int findPeak(int arr[], int left, int right){
    if(left > right) return -1;

    int mid = (left+right) / 2;

    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){ // 피크는 양쪽 값 둘 보다 커야함
        return mid;
    }
    if(arr[mid] > arr[mid-1]){
        return findPeak(arr, mid+1, right);
    }
    else return findPeak(arr, left, mid-1);
}

int main(){
    int arr[14] = { 12,15,20,25,32,35,40,45,31,26,12,8,7,3 };
    int n = 14;

    int find_idx = findPeak(arr, 0, n-1);

    if(find_idx >= 0){
        cout << arr[find_idx] << endl;
    }
    else{
        cout << find_idx << endl;
    }
}