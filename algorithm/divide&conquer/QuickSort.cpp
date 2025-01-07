#include <iostream>
#include <vector>
using namespace std;

int cnt_hoare, cnt_lomuto, cmp_hoare, cmp_lomuto;

vector<int> global_v;

int partition_hoare(int low, int high){
    int pivot = global_v[low];
    // do while 사용을 위해 초기값 변경
    int i = low - 1, j = high + 1;

    while(true){
        do{ i++; cmp_hoare++; } while (global_v[i] < pivot);
        do{ j--; cmp_hoare++; } while (global_v[j] > pivot);

        if(i < j){
            swap(global_v[i], global_v[j]);
            cnt_hoare++;
        }
        else{
            return j;
        }
    }
    
}

void quick_sort_hoare(int low, int high){
    if(low >= high) return;

    int p = partition_hoare(low, high);
    quick_sort_hoare(low, p);
    quick_sort_hoare(p+1, high);

}

int partition_lomuto(int low, int high){
    int pivot = global_v[low];
    int j = low;
    
    for(int i=low+1; i<=high; i++){
        cmp_lomuto++;
        if(global_v[i] < pivot){
            j++;
            swap(global_v[i], global_v[j]);
            cnt_lomuto++;
        }
    }

    cnt_lomuto++;
    swap(global_v[low], global_v[j]);
    return j;
}

void quick_sort_lomuto(int low, int high){
    if(low >= high) return;

    int p = partition_lomuto(low, high);
    quick_sort_lomuto(low, p-1);
    quick_sort_lomuto(p+1, high);
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, data;
        cin >> n;

        cnt_hoare = 0;
        cnt_lomuto = 0;
        cmp_hoare = 0;
        cmp_lomuto = 0;

        vector<int> v;
        for(int i=0; i<n; i++){
            cin >> data;
            v.push_back(data);
        }

        global_v = v;
        quick_sort_hoare(0, n-1);

        global_v = v;
        quick_sort_lomuto(0, n-1);

        cout << cnt_hoare << " ";
        cout << cnt_lomuto << " ";
        cout << cmp_hoare << " ";
        cout << cmp_lomuto << endl;
    }
}