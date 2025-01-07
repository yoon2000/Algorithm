#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int t, n, curr, next;
    cin >> t;

    while(t--){
        cin >> n;
        int arr[n+1];
        vector<int> visited(n+1, 0);

        // 입력 받기
        for(int i=1; i<n+1; i++){
            cin >> arr[i];
        }

        int answer = 0;
        for(int i=1; i<n+1; i++){
            if(!visited[i]){

                // bfs 돌리기
                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while(!q.empty()){
                    curr = q.front();
                    q.pop();

                    next = arr[curr];
                    if(!visited[next]){
                        q.push(next);
                        visited[next] = 1;
                    }
                }
                answer++;
            }
        }

        cout << answer << endl;
        
    }
}