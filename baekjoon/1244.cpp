#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, data, student_n;
    cin >> n;

    vector<int> v;
    v.push_back(-1);
    for(int i=0; i<n; i++){
        cin >> data;
        v.push_back(data);
    }

    cin >> student_n;
    while(student_n--){
        int a, sn;
        cin >> a >> sn;

        //남자
        if(a == 1){
            int cnt = 1;
            while(sn*cnt < n+1){
                v[sn*cnt] = !v[sn*cnt];
                cnt++;
            }
        }
        //여자
        if(a == 2){
            v[sn] = !v[sn];
            int cnt = 1;
            while(sn - cnt >= 1 && sn + cnt < n+1
            && v[sn-cnt] == v[sn+cnt]){
                v[sn-cnt] = !v[sn-cnt];
                v[sn+cnt] = !v[sn+cnt];
                cnt++;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        cout << v[i] << " ";
        if((i%20) == 0) cout << '\n';
    }
    cout << endl;
}