#include <iostream>
#include<cmath>
using namespace std;

void combSort(int arr[], int n);

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

        combSort(arr, n);
    }
}

void combSort(int arr[], int n){
    int cmp_cnt = 0, swap_cnt = 0;

    int gap = n;
    float shrink = 1.3;
    bool sorted = false;

    while(!sorted){
        gap = floor(gap/shrink);
        if(gap <= 1){
            gap = 1;
            sorted = true;
        }

        int i=0;
        while(i+gap < n){
            cmp_cnt++;
            if(arr[i] > arr[i+gap]){
                swap_cnt++;
                swap(arr[i], arr[i+gap]);
                sorted = false;
            }
            i++;
        }
    }

    cout << cmp_cnt << " " << swap_cnt << endl;
}