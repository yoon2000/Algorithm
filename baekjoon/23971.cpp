#include <iostream>
using namespace std;

int main(){
    int h, w, n, m;

    cin >> h >> w >> n >> m;

    int row_cnt = 0;
    int col_cnt = 0;

    int i = 0;
    while(i < w){
        row_cnt++;
        i += (m+1);
    }

    i = 0;
    while(i < h){
        col_cnt++;
        i += (n+1);
    }

    cout << (row_cnt * col_cnt) << endl;
}