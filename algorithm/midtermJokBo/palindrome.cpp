#include <iostream>
#include <string>
using namespace std;


string reverse_str(string str){  // 재귀로 판별
    if(str == "") return "";
    else{
        return reverse_str(str.substr(1)) + str[0];
    }
}


int palindrome(string str, int n){
    string re_str = reverse_str(str);

    if(str == re_str) return 1;
    else{
        return 0;
    }
}



int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string data;
        string str = "";
        for(int i=0; i<n; i++){
            cin >> data;
            str += data;
        }

        cout << palindrome(str, n) << endl;
        
    }
}