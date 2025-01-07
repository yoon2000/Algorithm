#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a, b, c;

    vector<int> v;

    while(true){

        cin >> a >> b >> c;

        v.clear();
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);

        if(!a && !b && !c){
            break;
        }

        if(a == b && b == c){
            cout << "Equilateral" << endl;
            continue;
        }

        int lagest = max(max(a, b), c);
        int sum = 0;
        int max_idx;
        
        for(int i=0; i<3; i++){
            if(v[i] == lagest){
               max_idx = i;
               break;
            }
        }

        for(int i=0; i<3; i++){
            if(i != max_idx){
                sum += v[i];
            }
        }

        if(sum > lagest){
            int before = -1;
            for(int i=0; i<3; i++){
                if(i != max_idx){
                    if(before == -1){
                        before = v[i];
                    }
                    else{
                        if(before == v[i] || v[max_idx] == before || v[max_idx] == v[i]){
                            cout << "Isosceles" << endl;
                        }
                        else{
                            cout << "Scalene" << endl;
                        }
                    }
                }
            }
            
        }

        else{
            cout << "Invalid" << endl;
        }

    }
}