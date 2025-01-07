#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int count_recursive_call;

void FindMinMax(vector<int> a, int low, int high, int& min_value, int& max_value){
    count_recursive_call++;
    int min1, min2, max1, max2;

    if(low == high){
        min_value = a[low];
        max_value = a[low];
    }
    else if((high - low) == 1){
        min_value = min(a[low], a[high]);
        max_value = max(a[low], a[high]);
    }
    else{
        int mid = (low + high) / 2;
        FindMinMax(a, low, mid, min1, max1);
        FindMinMax(a, mid+1, high, min2, max2);

        min_value = min(min1, min2);
        max_value = max(max1, max2);
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, data;
        cin >> n;
        count_recursive_call = 0;

        vector<int> a;
        for(int i=0; i<n; i++){
            cin >> data;
            a.push_back(data);
        }

        int min_value, max_value;
        FindMinMax(a, 0, n-1, min_value, max_value);

        cout << max_value << " " << min_value << " " << count_recursive_call << endl;
    }
}