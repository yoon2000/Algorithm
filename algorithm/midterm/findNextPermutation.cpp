#include <iostream>
#include <string>
using namespace std;

string reverse(string str){
    if(str == "") return "";
    else{
        return reverse(str.substr(1)) + str[0];
    }
}

string findNextPermutation(string str){
    int n = str.size();

    int i = n - 1;
    while( i >= 1 && str[i] < str[i-1]){
        i--;
    }
    i--;

    if( i == -1 ) return reverse(str); // 마지막 순열임

    int j = n-1;
    while( j >= i && str[j] < str[i]){
        j--;
    }

    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;

    string front_str = str.substr(0, i+1);
    string reverse_str = reverse(str.substr(i+1));
    return front_str + reverse_str;
}

void findAllPermutation(string str){
    string tmp = str;
    do{
        tmp = findNextPermutation(tmp);
        cout << tmp << endl;
    } while(tmp != str);
}

void permuteString(string data, int begin, int end){
    int range = end - begin;
    if(range == 1){
        cout << data << endl;
    }
    else{
        for(int i=0; i<range; i++){
            swap(data[begin], data[begin+i]);
            permuteString(data, begin + 1, end);
            swap(data[begin], data[begin+i]);
        }
    }
}

int main(){
    string str = "abc";
    string answer = findNextPermutation(str);
    cout << answer << endl;
    
    cout << "--------------" << endl;
    findAllPermutation(str);
    cout << "--------------" << endl;

    permuteString(str, 0, str.size());
}