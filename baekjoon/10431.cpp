#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    while(n--){
        int test_num, data, answer = 0;
        cin >> test_num;

        vector<int> v;
        cin >> data;
        v.push_back(data);

        for(int i=1; i<20; i++){
            cin >> data;

            int pos = v.size();
            for(int j=0; j<v.size(); j++){
                if(v[j] > data){
                    pos = j;
                    break;
                }
            }

            answer += (v.size() - pos);
            v.insert(v.begin() + pos, data);
        }

        cout << test_num << " " << answer << endl;
    }
}