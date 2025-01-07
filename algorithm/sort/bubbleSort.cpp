#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n);
void bubbleSortImproved1(int arr[], int n);
void bubbleSortImproved2(int arr[], int n);
void copyArray(int a[], int b[], int n) ;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, data;
        cin >> n;

        int a[n], b[n];
        for(int i=0; i<n; i++){
            cin >> data;
            a[i] = data;
            b[i] = data;
        }

        copyArray(a, b, n);
        bubbleSort(a, n);
        
        copyArray(a, b, n);
        bubbleSortImproved1(a, n);
        
        copyArray(a, b, n);
        bubbleSortImproved2(a, n);
    }
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int n){
    int cmp_cnt = 0, swap_cnt = 0;

    for(int i=1; i<n; i++){
        for(int j=1; j<=n-i; j++){
            cmp_cnt++;
            if(arr[j-1] > arr[j]){
                swap(&arr[j-1], &arr[j]);
                swap_cnt++;
            }
        }
    }

    cout << cmp_cnt << " " << swap_cnt << " ";
}


void bubbleSortImproved1(int arr[], int n){
    int cmp_cnt = 0, swap_cnt = 0;
    bool swapped;

    for(int i=1; i<n; i++){
        swapped = false;
        for(int j=1; j<=n-i; j++){
            cmp_cnt++;
            if(arr[j-1] > arr[j]){
                swap(&arr[j-1], &arr[j]);
                swapped = true;
                swap_cnt++;
            }
        }
        if(swapped == false){
            break;
        }
    }

    cout << cmp_cnt << " " << swap_cnt << " ";
}

void bubbleSortImproved2(int arr[], int n){
    int cmp_cnt = 0, swap_cnt = 0, lastSwappedPos = n, swappedPos;

    while(lastSwappedPos > 0){
        swappedPos = 0;
        for(int i=1; i<lastSwappedPos; i++){
            cmp_cnt++;
            if(arr[i-1] > arr[i]){
                swap(&arr[i-1], &arr[i]);
                swap_cnt++;
                swappedPos = i;
            }
        }
        lastSwappedPos = swappedPos;
    }

    cout << cmp_cnt << " " << swap_cnt << endl;
}

void copyArray(int a[], int b[], int n) { 
    for (int i = 0; i < n; i++) a[i] = b[i]; 
}