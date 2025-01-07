#include <iostream>
#include <vector>
#include <queue>
#include <cmath>  // floor 함수를 사용하기 위해 추가
using namespace std;

// 미구현 코드

int n, l, r;
vector<vector<int>> map;
int visited[51][51];
int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

bool is_in(int x, int y){
    if(x >= 0 && y >= 0 && x < n && y < n){
        return true;
    }
    return false;
}

bool is_open(int x, int y){
    if(map[x][y] >= l && map[x][y] <= r){  // 국경선 개방 조건 수정
        return true;
    }
    return false;
}

void bfs(int x, int y, int idx){  // 연합 형성 및 인구 이동을 위해 추가로 인덱스 값을 전달받음
    queue<pair<int, int>> q;
    vector<pair<int, int>> united;  // 연합을 이루는 나라들의 좌표 저장
    int population_sum = 0;  // 연합의 총 인구수
    int united_size = 0;  // 연합을 이루는 나라들의 개수

    q.push(make_pair(x, y));
    visited[x][y] = idx;
    united.push_back(make_pair(x, y));
    population_sum += map[x][y];
    united_size++;

    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int next_x = cur_x + dir[i][0];
            int next_y = cur_y + dir[i][1];

            if(is_in(next_x, next_y) && !visited[next_x][next_y] && is_open(next_x, next_y)){
                int diff = abs(map[cur_x][cur_y] - map[next_x][next_y]);  // 현재 나라와의 인구 차이 계산
                if(diff >= l && diff <= r){  // 국경선 개방 조건을 만족하면
                    q.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = idx;
                    united.push_back(make_pair(next_x, next_y));
                    population_sum += map[next_x][next_y];
                    united_size++;
                }
            }
        }
    }

    int united_population = floor(population_sum / united_size);  // 연합의 평균 인구수

    // 연합에 속한 모든 나라의 인구수 업데이트
    for(int i=0; i<united.size(); i++){
        int cur_x = united[i].first;
        int cur_y = united[i].second;
        map[cur_x][cur_y] = united_population;
    }
}

int main(){
    int day = 0;
    cin >> n >> l >> r;

    vector<int> temp_v;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int data;
            cin >> data;
            temp_v.push_back(data);
        }
        map.push_back(temp_v);
        temp_v.clear();
    }

    while(true){
        bool is_moved = false;  // 인구 이동이 발생했는지 확인하는 플래그

        // 초기화
        for(int i=0; i<n; i++){
            fill(visited[i], visited[i]+n, 0);
        }

        int idx = 1;  // 연합 인덱스

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){  // 방문하지 않은 나라인 경우
                    bfs(i, j, idx);
                    idx++;
                    is_moved = true;
                }
            }
        }

        if(!is_moved){  // 인구 이동이 더 이상 발생하지 않는 경우
            break;
        }

        day++;
    }

    cout << day << endl;

    return 0;
}
