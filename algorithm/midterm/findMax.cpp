#include <iostream>
using namespace std;

int recurMax(int arr[], int left, int right){
    int mid = (left + right) / 2;

    if(left == right) return arr[left];

    return max(recurMax(arr, left, mid), recurMax(arr, mid + 1, right));
}

int main(){
    int arr[11] = { 5,7,1,3,4,9,2,0,8,6,10 };
    int n = 11;

    int answer = recurMax(arr, 0, n-1);
    cout << answer << endl;
}