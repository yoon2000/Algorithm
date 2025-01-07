#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, data;
        cin >> n;

        vector<int> team(n, 0);
        vector<int> visited(n, 0);
        vector<int> v;
        for(int i=0; i<n; i++){
            cin >> data;
            v.push_back(data);
        }

        for(int std_num = 0; std_num < n; std_num++){
            int near_num = v[std_num] - 1;
            team[near_num] = std_num;
        }

        // for(auto i : team){
        //     cout << i << " ";
        // }
        // cout << endl;

        int team_cnt = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                visited[i] = 1;
                team_cnt++;
                
                int near = team[i];
                while(!visited[near]){
                    visited[near] = 1;
                    near = team[near];
                }
            }
        }

        cout << team_cnt << endl;

    }
}