#include <iostream>
#include <set>
using namespace std;

int second_arr[101];
set<int> answer;

int n;

void dfs(int curr, set<int> up, set<int> down){
    // bound
    if(curr < n){
        // pick
        set<int> pick_up(up), pick_down(down);
        pick_up.insert(curr+1);
        pick_down.insert(second_arr[curr]);

        if(pick_up == pick_down && pick_up.size() >= 1){
            if(answer.size() < pick_up.size()){
                answer = pick_up;
            }
        }
        else if(up == down && up.size() >= 1){
            if(answer.size() < up.size()){
                answer = up;
            }
        }

        dfs(curr+1, up, down); // no pick
        dfs(curr+1, pick_up, pick_down); // pick
    }


}

int main(){
    int data;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> data;
        second_arr[i] = data;
    }

    set<int> temp;
    dfs(0, temp, temp);

    cout << answer.size() << '\n';
    for(auto i : answer){
        cout << i << '\n';
    }

}