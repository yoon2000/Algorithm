#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, data;
        cin >> n;

        vector<int> v;
        for(int i=0; i<n; i++){
            cin >> data;
            v.push_back(data);
        }

        int temp_answer = 1, answer = 1;
        for(int i=1; i<n; i++){
            if(v[i] >= v[i-1]){
                temp_answer++;
            }
            else{
                answer = max(temp_answer, answer);
                temp_answer = 1;
            }
        }

        answer = max(temp_answer, answer);

        cout << answer << endl;
    }
}