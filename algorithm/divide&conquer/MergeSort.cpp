#include <iostream>
#include <vector>
#define MAX_SIZE 101
using namespace std;


int cnt;
vector<int> v;

void merge(int low, int mid, int high){
    int i, j, k;
    int tmp[MAX_SIZE];

    for(i=low; i<=high; i++){
        tmp[i] = v[i];
    }

    i = k = low;
    j = mid + 1;
    while(i <= mid && j <= high){
        cnt++;
        if(tmp[i] <= tmp[j]){
            v[k++] = tmp[i++];
        }
        else{
            v[k++] = tmp[j++];
        }
    }

    while(i<=mid) v[k++] = tmp[i++];
    while(j<=high) v[k++] = tmp[j++];
}

void mergeSort(int low, int high){
    int mid;

    if(low == high) return;

    mid = (low + high) / 2;

    mergeSort(low, mid);
    mergeSort(mid+1, high);
    merge(low, mid, high);

}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, data;
        cin >> n;

        cnt = 0; v.clear();
        for(int i=0; i<n; i++){
            cin >> data;
            v.push_back(data);
        }

        mergeSort(0, n-1);
        
        cout << cnt << endl;
    }

}