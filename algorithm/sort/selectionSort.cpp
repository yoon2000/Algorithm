#include <iostream>
using namespace std;

void selectionSort(int arr[], int n);

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

        selectionSort(arr, n);
    }
}

void selectionSort(int arr[], int n){
    int cmp_cnt = 0, swap_cnt = 0, jmin;

    for(int i=0; i<n; i++){
        jmin = i;
        for(int j=i+1; j<n; j++){
            cmp_cnt++;
            if(arr[j] < arr[jmin]){
                jmin = j;
            }
        }
        if(jmin != i){
            swap(arr[i], arr[jmin]);
            swap_cnt++;
        }
    }

    cout << cmp_cnt << " " << swap_cnt << endl;
}