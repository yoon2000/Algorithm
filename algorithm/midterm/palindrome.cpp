#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string str, int first, int last){
    if(first > last){
        return true;
    }
    else{
        if(str[first] != str[last]){
            return false;
        }
        else{
            return checkPalindrome(str, first+1, last-1);
        }
    }
}

int main(){
    string str = "malayalam";
    cout << checkPalindrome(str, 0 , 8) << endl;
}