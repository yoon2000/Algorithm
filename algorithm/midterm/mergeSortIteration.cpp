#include <iostream>
#define MAX_SIZE 100
using namespace std;

int arr[14] = { 12,15,20,25,32,35,40,45,31,26,12,8,7,3 };
int n = 14;

void merge(int left, int mid, int right){
    int tmp[MAX_SIZE];

    int i, j, k;

    for(i=left; i<=right; i++){
        tmp[i] = arr[i];
    }

    i = k = left;
    j = mid+1;

    while(i <= mid && j <= right){
        if(tmp[i] <= tmp[j]){
            arr[k++] = tmp[i++];
        }
        else{
            arr[k++] = tmp[j++];
        }
    }

    while(i <= mid) arr[k++] = tmp[i++];
    while(j <= right) arr[k++] = tmp[j++];
}

void mergeSort(){
    int sz = 1;
    while(sz < n){
        for(int i=0; i<n; i += 2*sz){ 
            // 왜 sz의 2배를 더해줄까? 
            // [1, 2] [3, 4] [5 ...  <<  1위치에서 sz 2인 두개 배열을 합치는 거니까
            // sz*2 = 4를 더해줘야 다음 5로 가는구나

            int low = i;
            int mid = low + sz - 1; // 1을 빼는 이유 low를 포함한 상태로 sz더해서 있어서
            int high = min(low+(2*sz)-1, n-1);
            if(mid >= n-1) break;
            merge(low, mid, high);
        }
        sz *= 2;
    }
}

int main(){
   mergeSort();

   //정렬된 배열 출력하기
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}