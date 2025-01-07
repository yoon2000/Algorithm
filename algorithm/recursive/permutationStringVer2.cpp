#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<string> result;

void permuteString(string data, int begin, int end){
    int range = end - begin;
    if(range == 1){
        result.push_back(data);
    }
    else{
        for(int i=0; i<range; i++){
            swap(data[begin], data[begin+i]);
            permuteString(data, begin + 1, end);
            swap(data[begin], data[begin+i]);
        }
    }
}

int weight_str(string str){
    int weight = 0;
    for(int i=0; i<str.length(); i++){
        if(i % 2){
            weight += (-1) * (str[i] - 'a');
        }
        else{
            weight += (str[i] - 'a');
        }
    }
    return weight;
}

int main(){
    int t;
    cin >> t;

    while(t--){

        string data;
        cin >> data;

        permuteString(data, 0, data.length());

        for(auto i : result){
            cout << i << endl;
        }
        cout << endl;

        // int answer = 0;
        // for(auto str: result){
        //     if(weight_str(str) > 0){
        //         answer++;
        //     }
        // }

        // cout << answer << endl;
        result.clear();
    }

    return 0;
}