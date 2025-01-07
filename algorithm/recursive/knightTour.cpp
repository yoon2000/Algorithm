#include <iostream>
using namespace std;

#define MAXSIZE 9
#define MARK 1
#define UNMARK 0

typedef struct Point{
    int x;
    int y;
} point;

point direction[8] = {{1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}};

int board[MAXSIZE][MAXSIZE];
int path[MAXSIZE][MAXSIZE];

int knightTour (int m, int n, point pos, int counter){
    point next;
    if(counter == m*n) return 1;

    for(int i=0; i<8; i++){
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if(next.x >= 0 && next.y >= 0
        && next.x < n && next.y < m
        && board[next.y][next.x] != MARK){
            board[next.y][next.x] = MARK;
            path[next.y][next.x] = counter+1;

            if(knightTour(m, n, next, counter+1)){
                return 1;
            }
            board[next.y][next.x] = UNMARK;
        }
    }
    return 0; // all paths are blocked
}

int main(){
    int test_case;
    cin >> test_case;

    while(test_case--){
        int m, n, s, t;
        cin >> m >> n >> s >> t;

        for(int i=0; i<MAXSIZE; i++){
            for(int j=0; j<MAXSIZE; j++){
                board[i][j] = UNMARK;
                path[i][j] = UNMARK;
            }
        }

        board[s-1][t-1] = MARK;
        path[s-1][t-1] = 1;

        point start;
        start.y = s-1;
        start.x = t-1;

        if(knightTour(m, n, start, 1)){
            cout << 1 << endl;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    cout << path[i][j] << " ";
                }
                cout << endl;
            }
        }
        else{
            cout << 0 << endl;
        }

    }

    return 0;
}