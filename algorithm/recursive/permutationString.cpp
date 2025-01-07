#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<string> result;
vector<int> visited(11, 0);

void dfs(string data, string str){
    if(str.length() == data.length()){
        result.push_back(str);
    }
    else{
        for(int i=0; i<data.length(); i++){
            if(visited[i] == 0){
                visited[i] = 1;
                dfs(data, str + data[i]);
                visited[i] = 0;
            }
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
        for(int i=0; i<11; i++){
            visited[i] = 0;
        }

        string data;
        cin >> data;

        dfs(data,"");

        int answer = 0;
        for(auto str: result){
            cout << str << " ";
            if(weight_str(str) > 0){
                answer++;
            }
        }
        cout << endl;

        cout << answer << endl;
        result.clear();
    }

    return 0;
}