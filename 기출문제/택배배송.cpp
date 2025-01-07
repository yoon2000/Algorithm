#include <iostream>
#include <limits.h>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int n, m, hi_w, lo_w, mid_w;

bool bfs(vector<pair<int,int>> *graph, int start, int end){

  int check[n+1], curr;
  for(int i=1; i<n+1; i++){
    check[i] = 0;
  }

  set<int> visited;
  queue<int> q;

  visited.insert(start);     // 시작위치 설정
  q.push(start);

  while(!q.empty()){
    curr = q.front();
    q.pop();
    for(auto next : graph[curr]){
      if(!visited.count(next.first) && next.second >= mid_w){
        visited.insert(next.first); // 방문 기록
        q.push(next.first);
      }
    }
  }
  return visited.count(end);
}

int main(){
  int test_num;
  int a, b, w, start, end;
  cin >> test_num;

  for(int quit=0; quit<test_num; quit++){

    cin >> n >> m >> start >> end;

    vector<pair<int,int>> graph[n+1]; // graph 그리기
    for(int i=0; i<m; i++){
      cin >> a >> b >> w;
      hi_w = max(hi_w, w);
      graph[a].push_back(make_pair(b,w));
      graph[b].push_back(make_pair(a,w));
    }

    while(lo_w + 1 < hi_w){           // 이분탐색 해보기
      mid_w = (lo_w + hi_w) / 2;
      if(bfs(graph, start, end)){     // 중간중량이 무사히 도착
        lo_w = mid_w;
      }
      else{
        hi_w = mid_w;
      }
    }

    mid_w = hi_w;
    if(bfs(graph, start, end)){
      cout << hi_w << endl;
    }
    else cout << lo_w << endl;

    lo_w = 0;
  }
}
