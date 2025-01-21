#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, data;
        cin >> n;

        unordered_map<int, int> um;
        vector<int> v;
        for(int i=0; i<n; i++){
            cin >> data;
            v.push_back(data);
            if(um.count(data)){
                um[data]++;
            }
            else{
                um[data] = 1;
            }
        }
        
        unordered_map<int,int> score;
        unordered_map<int, vector<int>> team_ranks;
        int rank = 1;
        for(int i=0; i<n; i++){
            data = v[i];
            if(um[data] != 6) continue;

            team_ranks[data].push_back(rank);

            if(score.count(data)){
                if(team_ranks[data].size() <= 4){
                    score[data] += rank;
                }
                rank++;
            }
            else{
                score[data] = rank++;
            }
        }

        int min_score = INT_MAX;
        int first_team = -1;
        int min_fifth_rank = INT_MAX;
        for(auto i : score){
            int team_name = i.first;
            int team_score = i.second;

            if(team_score < min_score){
                min_score = team_score;
                first_team = team_name;
                min_fifth_rank = team_ranks[team_name][4];
            }
            else if(team_score == min_score){
                if(team_ranks[team_name][4] < min_fifth_rank){
                    first_team = team_name;
                    min_fifth_rank = team_ranks[team_name][4];
                }
            }
        }

        cout << first_team << endl;
    }
}