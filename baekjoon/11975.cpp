#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 미구현 

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int main(){
    int n, dir_num;
    string str;

    cin >> n;
    cin >> str;

    vector<vector<int>> map(2*n+1, vector<int>(2*n+1, 0));
    pair<int,int> pos;
    pos = make_pair(n-1, n-1);

    for(int i=0; i<str.length(); i++){
        char mv = str[i];
        
        if(mv == 'N'){
            dir_num = 0;
        }
        else if (mv == 'S')
        {
            dir_num = 1;
        }
        else if (mv == 'E')
        {
            dir_num = 2;
        }
        else{
            dir_num = 3;
        }
        
        map[pos.first][pos.second] = 1;
        pos.first = pos.first + dir[dir_num][0];
        pos.second = pos.second + dir[dir_num][1];
    }

    for(auto i : map){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
