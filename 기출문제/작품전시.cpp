#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class art{

    public:
    int id;
    int recommand;
    int time_stamp;

    art(int a=0, int b=0, int c=0):id(a), recommand(b), time_stamp(c){}
};

struct cmp{
    bool operator()(art a, art b){
        if(a.recommand == b.recommand){
            return a.time_stamp > b.time_stamp;
        }
        return a.recommand > b.recommand;
    }
};

int main(){
    int t;
    cin >> t;

    int n, m, id, time_v;
    while(t--){
        cin >> n >> m;

        vector<int> recommand(101,0);
        vector<int> is_in(101,0);
        vector<int> time_stamp(101,0);
        priority_queue<art, vector<art>, cmp> board;
        

        art data;
        for(int time=1; time<m+1; time++){
            cin >> id;
            // board에 들어가있을경우 pq 뺏다가 다 넣어야함
            if(is_in[id]){
                recommand[id]++;
                priority_queue<art, vector<art>, cmp> temp;
                temp.push(art(id, recommand[id], time_stamp[id]));

                while(!board.empty()){
                    data = board.top(); board.pop();
                    if(data.id == id){
                        continue;
                    }
                    temp.push(data);
                }
                board = temp;
                
            }
            else{ // board에 없을경우
                if(board.size() + 1 > n){
                    data = board.top();
                    board.pop();
                    is_in[data.id] = 0;
                }

                // 무조건 넣어주어야함
                is_in[id] = 1;
                // 처음 들어갈때 무조건 추천 1
                recommand[id] = 1;

                time_stamp[id] = time;
                board.push(art(id, recommand[id], time_stamp[id]));
            }
        }

        vector<int> answer;
        while(!board.empty()){
            data = board.top(); board.pop();
            answer.push_back(data.id);
        }
        
        sort(answer.begin(), answer.end());
        for(auto i : answer){
            cout << i << " ";
        }
        cout << endl;
    }
}