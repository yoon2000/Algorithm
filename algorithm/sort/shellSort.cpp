#include <iostream>
#include<cmath>
using namespace std;

void shellSort(int arr[], int n);

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        shellSort(arr, n);
    }
}

void shellSort(int arr[], int n){
    int cmp_cnt = 0, swap_cnt = 0;

    int shrinkRatio = 2;
    int gap = (n / shrinkRatio);

    while(gap > 0){
        for(int i=gap; i<n; i++){
            int tmp = arr[i];
            for(int j=i; j >= gap; j -= gap){
                cmp_cnt++;
                if(arr[j-gap] > tmp){
                    arr[j] = arr[j-gap];
                    arr[j-gap] = tmp;
                    swap_cnt++;
                }
                else{
                    break;
                }
            }
        }
        gap /= shrinkRatio;
    }

    cout << cmp_cnt << " " << swap_cnt << endl;
}