#include <iostream>
#include <set>
#include <limits.h>
#include <vector>
using namespace std;

int n, m;

//bfs와 이진탐색을 함께 사용하는 문제 !

//visited set, array short path distance, array prev 필요

void dijkstra(vector<pair<int,int>> *graph, int start, int end){
  set<int> visited;                               //visited 체크할 set

  int distance[n+1];                              // 거리 후보들을 넣을 배열
  for(int i=1; i<n+1; i++){                       // 거리값 무한대로 초기화
    distance[i] = INT_MAX;
  }

  int prev[n+1];                                  // 해당 위치의 전 노드를 넣을 배열

  distance[start] = 0;                            // 시작지점에서 시작지점까지 거리 0으로 넣어주기
  visited.insert(start);
  for(auto node : graph[start]){                  // 시작지점에서 연결된 노드 찾기
    int next_node = node.first;
    int len = node.second;
    distance[next_node] = min(distance[next_node], distance[start] + len);
  }

  int min_dis, u;                                // 후보로 발탁될 노드 찾는 변수
  while(visited.size() != n){                    // 모든 노드 거리 찾을때까지

    min_dis = INT_MAX;                           // 후보정할 변수 초기값 무한대로 설정
    for(int i=1; i<n+1; i++){                    // 후보 찾기
      if(!visited.count(i) && distance[i] < min_dis){
          min_dis = distance[i];
          u = i;
      }
    }

    visited.insert(u);                          // 발탁된 후보 추가
    for(auto node : graph[u]){                  // 후보 주변 노드 탐색 및 거리, 이전노드값 갱신
      int next_node = node.first;
      int len = node.second;
      if(!visited.count(next_node) && distance[u] + len < distance[next_node]){
        distance[next_node] = distance[u] + len;
        prev[next_node] = u;
      }
    }
  }

  cout << distance[end] << endl;
}

int main(){
  int test_num, start, end, a, b, w;
  //testcase run
  cin >> test_num;

  for(int i=0; i<test_num; i++)
  {
    cin >> n >> m >> start >> end;

    //graph 그리기
    vector<pair<int,int>> graph[n+1];
    for(int j=0; j<m; j++){
      cin >> a >> b >> w;
      graph[a].push_back(make_pair(b, w));
      graph[b].push_back(make_pair(a, w));
    }

    //dijkstra 실행
    dijkstra(graph, start, end);
  }
}
