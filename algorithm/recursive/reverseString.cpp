#include <iostream>
#include <string>
using namespace std;

string reverse_string(string str){
    if(str == ""){
        return "";
    }
    else{
        return reverse_string(str.substr(1)) + str[0];
    }
}


int main(){
    int t;
    cin >> t;

    while(t--){
        string data;
        cin >> data;

        cout << reverse_string(data) << endl;
    }
}