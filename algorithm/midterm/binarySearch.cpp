#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int k){

    if(left > right) return -1; // 중요!! 찾지 못했을 때는 이렇게 조건문으로 알아야함

    int mid = (left + right) / 2;
    if(arr[mid] == k){
        return mid;
    }
    if(arr[mid] < k){
        return binarySearch(arr, mid+1, right, k);
    }
    else{
        return binarySearch(arr, left, mid-1, k);
    }
}

int main(){
    int arr[11] = { 2,4,6,8,10,12,14,16,18,20,22 };
    int n = 11;
    int k = 10; // 찾을 수

    int find_idx = binarySearch(arr, 0, n-1, k);

    if(find_idx >= 0){
        cout << arr[find_idx] << endl;
    }
    else{
        cout << find_idx << endl;
    }
}