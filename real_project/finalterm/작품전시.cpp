#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

struct art
{
    int id;
    int rec;
    int timestamp;
    art(int a, int b, int c):id(a), rec(b), timestamp(c){}
};

struct cmp{
    bool operator()(art a, art b){
        if(a.rec == b.rec){
            return a.timestamp > b.timestamp;
        }
        return a.rec > b.rec;
    }
};


int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n;
        cin >> m;

        int id;
        priority_queue<art, vector<art>, cmp> board;
        vector<int> is_in(101, 0);
        art data(0,0,0);

        for(int i=0; i<m; i++){
            cin >> id;
            if(is_in[id]){
                priority_queue<art, vector<art>, cmp> temp;
                while(!board.empty()){
                    data = board.top(); board.pop();
                    if(data.id == id){
                        temp.push(art(data.id, data.rec+1, data.timestamp));
                    }
                    else{
                        temp.push(data);
                    }
                }
                board = temp;
            }
            else{
                if(board.size()+1 <= n){
                    board.push(art(id, 1, i));
                    is_in[id] = 1;
                }
                else{
                    data = board.top(); board.pop();
                    board.push(art(id, 1, i));
                    is_in[id] = 1;
                    is_in[data.id] = 0;
                }
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