#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    string str;

    cin >> n;

    vector<string> v;

    for(int i=0; i<n; i++){
        cin >> str;
        v.push_back(str);
    }

    int idx1, idx2;
    for(int i=0; i<n; i++){
        if(v[i] == "KBS1") idx1 = i;
        else if(v[i] == "KBS2") idx2 = i;
    }

    for(int i=0; i<idx1; i++){
        cout << 1;
    }
    for(int i=0; i<idx1; i++){
        cout << 4;
    }

    if(idx1 > idx2) idx2++;

    for(int i=0; i<idx2; i++){
        cout << 1;
    }
    for(int i=0; i<idx2-1; i++){
        cout << 4;
    }
    cout << endl;
}