#include <iostream>
#include <string>
using namespace std;

/*
4
6 13
551063
1347551063120
6 6
551063
551063
6 3
551063
551
6 12
551055
865510551055
*/
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        string psw, in_data;
        cin >> psw;
        cin >> in_data;

        int check = in_data.find(psw);
        if(check == string::npos) cout << 0 << endl;
        else cout << 1 << endl;

    }
}