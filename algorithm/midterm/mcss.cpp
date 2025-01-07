#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int mcss(int arr[], int n, int left, int right){
    if(left == right) return arr[left];

    int mid = (left+right) / 2;
    int left_max = mcss(arr, n, left, mid);
    int right_max = mcss(arr, n, mid+1, right);

    int left_part = INT_MIN;
    int right_part = INT_MIN;
    int tmp = 0;
    for(int i=mid; i >= left; i--){
        left_part = max(left_part, tmp += arr[i]);
    }

    tmp = 0;
    for(int i=mid+1; i<=right; i++){
        right_part = max(right_part, tmp += arr[i]);
    }

    return max(max(left_max, right_max), left_part + right_part);

}

int main(){
    int n = 10;
    int arr[10] = { 5, -7, 2, 3, -4, 5, 2, -7, 8, -7 };

    cout << mcss(arr, n, 0, n-1) << endl;
}