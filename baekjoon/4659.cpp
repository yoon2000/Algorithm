#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(); 

    vector<string> map;

    for(int i=0; i<n; i++){
        string data;
        getline(cin, data);
        map.push_back(data);
    }

    pair<int,int> head;
    bool break_flag = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == '*'){
                head = make_pair(i,j);
                break_flag = true;
                break;
            }
        }
        if(break_flag) break;
    }

    int left_arm, right_arm, left_leg, right_leg, body_len;

    // left_arm
    for(int i=0; i<n; i++){
        if(map[head.first+1][i] == '*'){
            left_arm = head.second - i;
            break;
        }
    }

    // right_arm
    for(int i=n-1; i>=0; i--){
        if(map[head.first+1][i] == '*'){
            right_arm = i - head.second;
            break;
        }
    }

    // body_len
    body_len = 0;
    for(int i=head.first+2; i<n; i++){
        if(map[i][head.second] == '*'){
            body_len++;
        }
        else{
            break;
        }
    }

    pair<int,int> leg = make_pair(head.first+body_len+1, head.second);

    //left_leg
    left_leg = 0;
    for(int i=leg.first+1; i<n; i++){
        if(map[i][leg.second-1] == '*'){
            left_leg++;
        }
        else{
            break;
        }
    }

    //right_leg
    right_leg = 0;
    for(int i=leg.first+1; i<n; i++){
        if(map[i][leg.second+1] == '*'){
            right_leg++;
        }
        else{
            break;
        }
    }

    cout << head.first+2 << " " << head.second+1 << endl;
    cout << left_arm << " " << right_arm << " "
    << body_len << " " << left_leg << " " << right_leg << endl;
}   