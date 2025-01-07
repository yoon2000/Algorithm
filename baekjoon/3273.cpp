#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, temp, goal_int;
    vector<int> v;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    cin >> goal_int;

    int left = 0;
    int right = n-1;
    int answer = 0;

    while(left < right){
        int sum = v[left] + v[right];
        if(sum == goal_int){
            answer++;
            left++;
            right--;
        }
        else if(sum > goal_int) right--;
        else left++;
    }

    cout << answer << endl;
}