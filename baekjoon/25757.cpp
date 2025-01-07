#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    set<string> s;

    int n;
    char game;
    string data;

    cin >> n >> game;

    for(int i=0; i<n; i++){
        cin >> data;
        s.insert(data);
    }

    if(game == 'Y'){
        cout << s.size() << endl;
    }
    else if(game == 'F'){
        cout << s.size() / 2 << endl;
    }
    else{
        cout << s.size() / 3 << endl;
    }
}