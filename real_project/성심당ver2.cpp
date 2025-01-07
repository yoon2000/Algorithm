#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int dir[4][2] = {{-1,0}, {0,-1}, {0,1}, {1,0}};
int dir_r[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};
int is_market[16][16];
int is_house[16][16];
int is_block[16][16];

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

pair<int,int> bfs(pair<int,int> point, vector<pair<int,int>> house, int n){
    vector<vector<int>> visited(n, vector<int>(n,0));
    vector<vector<int>> distance(n, vector<int>(n,9999));

    queue<pair<int,int>> q;
    q.push(point);
    visited[point.first][point.second] = 1;
    distance[point.first][point.second] = 1;

    while(!q.empty()){
        point = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int x = point.first + dir[i][0];
            int y = point.second + dir[i][1];
            if(x >= 0 && x < n && y >= 0 && y < n
            && !visited[x][y] && !is_block[x][y]){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
                distance[x][y] = distance[point.first][point.second] + 1;
            }
        }
    }

    int min_v = 9999;
    pair<int,int> destination;
    for(auto i : house){
        int x = i.first; int y = i.second;
        min_v = min(min_v, distance[x][y]);
    }
    for(auto i : house){
        int x = i.first; int y = i.second;
        if(distance[x][y] == min_v && !is_block[x][y]){
            destination = make_pair(x, y);
            is_block[x][y] = 1;
            break;
        }   
  }
  return destination;
}

pair<int,int> move_one(pair<int,int> person, pair<int,int> market, int n){
    vector<vector<int>> visited(n, vector<int>(n,0));
    vector<vector<int>> distance(n, vector<int>(n,9999));

    visited[market.first][market.second] = 1;
    distance[market.first][market.second] = 1;
    queue<pair<int,int>> q;
    q.push(market);

    pair<int,int> point;
    int x, y;
    bool escape = false;
    while(!q.empty()){
        point = q.front(); q.pop();
        for(int i=0; i<4; i++){
            x = point.first + dir_r[i][0];
            y = point.second + dir_r[i][1];
            if(x >= 0 && x < n && y >= 0 && y < 0
            && !visited[x][y] && !is_block[x][y]){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
                distance[x][y] = distance[point.first][point.second] + 1;
                if(x == person.first && y == person.second){
                    escape = true;
                    break;
                }
            }
        }
        if(escape){
            break;
        }
    }

    int min_v = 9999;
    for(int i=0; i<4; i++){
        x = person.first + dir[i][0];
        y = person.second + dir[i][1];
        if(x >= 0 && x < n && y >= 0 && y < n && !is_block[x][y]){
            min_v = min(min_v, distance[x][y]);
        }
    }

    for(int i=0; i<4; i++){
        x = person.first + dir[i][0];
        y = person.second + dir[i][1];
        if(x >= 0 && x < n && y >= 0 && y < n
        && !is_block[x][y] && distance[x][y] == min_v){
            return make_pair(x,y);
        }
    }

}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m, data;
        cin >> n >> m;

        vector<pair<int,int>> house;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> data;
                
                // is배열들 다시쓰기위해서 초기화 해주기 
                is_market[i][j] = 0;
                is_house[i][j] = 0;
                is_block[i][j] = 0;

                if(data){
                    // house 위치 기록
                    is_house[i][j] = 1;
                    house.push_back(make_pair(i,j));
                }
            }
        }

        // house sort
        // sort(house.begin(), house.end(), cmp);
        
        // market 위치 기록. 배열들 0행 기준으로 하기위해 좌표값 -1 해주기
        int x, y;
        vector<pair<int,int>> market;
        market.push_back(make_pair(0,0));
        for(int i=0; i<m; i++){
            cin >> x >> y;
            is_market[x-1][y-1] = 1;
            market.push_back(make_pair(x-1,y-1));
        }

        // 시간 돌리면서 시물레이션 구현하기!
        int minute = 0;
        vector<pair<int,int>> person;

        // 도착한 사람 번호 집합
        set<int> s;

        int time;
        while(s.size() < m){
            minute++;

            if(minute > m){
                time = m;
            }
            else{
                time = minute;
            }

            for(int i=0; i<time; i++){
                // 사람 넣기
                if(i+1 == minute && person.size() == i){
                    person.push_back(bfs(market[i], house, n));
                    cout << "person_push [" << i+1 << "] = " << person[i].first << ", " << person[i].second << endl;
                }
                else if(!s.count(i)){
                    // 한칸 이동시키기
                    person[i] = move_one(person[i], market[i], n);
                    cout << "point : " << person[i].first << ", " << person[i].second << endl;
                    // 원하는 가게 들어왔으면 집합에 넣기
                    if(!s.count(i) && person[i] == market[i]) s.insert(i);
                }
                // 사람들이 현재 가게 위에 있으면 길 막기
                for(auto k : person){
                    if(is_market[k.first][k.second]){
                        is_block[k.first][k.second] = 1;
                    }
                }
            }
        }
        cout << minute << endl;
    }
}