#include <iostream>
#include <string>
using namespace std;

int main(){
    string data;
    cin >> data;
    string mo = "aeiou";

    while(data != "end"){
        bool answer = false;

        // 조건 1, 모음 하나 반드시 포함
        for(auto i : data){
            if(mo.find(i) != string::npos){
                answer = true;
                break;
            }
        }

        // 조건 2, 모음 3개 or 자음 3개 연속 X
        int mo_cnt = 0, ja_cnt = 0;
        for(auto i : data){
            if(mo.find(i) != string::npos){
                mo_cnt++; ja_cnt = 0;
                if(mo_cnt >= 3){
                    answer = false;
                    break;
                }
            }
            else{
                mo_cnt = 0; ja_cnt++;
                if(ja_cnt >= 3){
                    answer = false;
                    break;
                }
            }
        }

        //조건 3, 같은글자 연속 2번 X (ee, oo는 허용)
        for(int i=1; i<data.size(); i++){
            if(data[i] == data[i-1]){
                if(data[i] != 'e' && data[i] != 'o'){
                    answer = false;
                    break;
                }
            }
        }


        //출력하기
        if(answer){
            cout << "<" << data << ">" << " is acceptable." << endl;
        }
        else{
            cout << "<" << data << ">" << " is not acceptable." << endl;
        }

        cin >> data;
    }
}