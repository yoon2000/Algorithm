#include <iostream>
using namespace std;

void insertionSort(int a[], int n);

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
        insertionSort(arr, n);
    }
}

void insertionSort(int a[], int n){
    int cmp_cnt = 0, swap_cnt = 0;

    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            cmp_cnt++;

            if(a[j-1] > a[j]){
                swap(a[j-1], a[j]);
                swap_cnt++;
            }
            else{
                break;
            }
        }
    }

    cout << cmp_cnt << " " << swap_cnt << endl;       
}