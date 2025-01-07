#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check_head(int i, int j, vector<string> map);
bool check_leg(int i, int j, vector<string> map);

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //아래 3개 점 -> 머리
    //아래 2개 점 + 중간에 뚫림 -> 가랑이 시작
    int n, m;
    cin >> n;

    vector<string> map;
    string data;
    for(int i=0; i<n; i++){
        cin >> data;
        map.push_back(data);
    }

    m = map[0].size();

    pair<int,int> head, leg;

    bool find_head = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // find head & leg
            if(map[i][j] == '*'){
                if(check_head(i, j, map)){
                    head = make_pair(i,j);
                    find_head = true;
                    break;
                }
            }
        }
        if(find_head) break;
    }

    for(int i=head.first+1; i<n; i++){
        if(check_leg(i,head.second,map)){
            leg = make_pair(i,head.second);
        }
    }


    pair<int,int> heart = make_pair(head.first + 1, head.second);
    int left_arm = 0, right_arm = 0, waist = 0, left_leg = 0, right_leg = 0;

    // 왼쪽 팔
    for(int i = 0; i < heart.second; i++){
        if(map[heart.first][i] == '*') left_arm++;
    }

    // 오른쪽 팔
    for(int i = heart.second + 1; i < m; i++){
        if(map[heart.first][i] == '*') right_arm++;
    }

    // 허리
    for(int i = heart.first + 1; i < n; i++){
        if(map[i][heart.second] == '*') waist++;
    }

    // 왼쪽 다리
    for(int i = leg.first + 1; i < n; i++){
        if(map[i][leg.second - 1] == '*') left_leg++;
    }

    // 오른쪽 다리
    for(int i = leg.first + 1; i < n; i++){
        if(map[i][leg.second + 1] == '*') right_leg++;
    }

    cout << heart.first+1 << " " << heart.second+1 << '\n';

    cout << left_arm << " " << right_arm<< " " << waist << " " 
    << left_leg << " " << right_leg << " " << '\n';
}

bool check_head(int i, int j, vector<string> map) {
    // 인덱스 범위 체크
    if (i + 1 < map.size() && j - 1 >= 0 && j + 1 < map[i].size()) {
        if (map[i + 1][j - 1] == '*' && map[i + 1][j] == '*' && map[i + 1][j + 1] == '*') {
            return true;
        }
    }
    return false;
}

bool check_leg(int i, int j, vector<string> map) {
    // 인덱스 범위 체크
    if (i + 1 < map.size() && j - 1 >= 0 && j + 1 < map[i].size()) {
        if (map[i + 1][j - 1] == '*' && map[i + 1][j] == '_' && map[i + 1][j + 1] == '*') {
            return true;
        }
    }
    return false;
}
