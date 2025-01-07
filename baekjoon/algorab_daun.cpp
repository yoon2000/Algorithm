#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;

    string str = "";
    while(t--){
        int k;
        cin >> k;
        for(int i=1; i<=k; i++){
            str += i;
            if(str.size() >= k){
                break;
            }
        }
        cout << str[k-1] << endl;
    }
    
}