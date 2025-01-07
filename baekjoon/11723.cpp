#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> s(21, 0);

    int m;
    cin >> m;

    string signal;
    int data;
    for(int i=0; i<m; i++){
        cin >> signal;
        
        if(signal == "all"){
            for(int i=1; i<21; i++){
                s[i] = 1;
            }
            continue;
        }

        else if(signal == "empty"){
            for(int i=1; i<21; i++){
                s[i] = 0;
            }
            continue;
        }

        cin >> data;

        if(signal == "add") s[data] = 1;
        else if(signal == "remove") s[data] = 0;
        else if(signal == "check") cout << s[data] << '\n';
        else if(signal == "toggle"){
            if(s[data]) s[data] = 0;
            else s[data] = 1;
        }
    }
}