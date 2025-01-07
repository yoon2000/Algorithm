#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, data;
        vector<int> v;
        cin >> n;

        for(int i=0; i<n; i++){
            cin >> data;
            v.push_back(data);
        }

        int first = v[0], temp_answer = 0, answer = 1;

        for(auto i : v){
            if(i >= first){
                temp_answer++;
            }
            else{
                answer = max(temp_answer, answer);
                temp_answer = 1;
                first = i;
            }
        }

        answer = max(temp_answer, answer);

        cout << answer << endl;

    }
}