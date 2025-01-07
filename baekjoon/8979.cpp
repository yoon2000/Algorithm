#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class country{
public:
    int num;
    int gold_cnt;
    int silver_cnt;
    int bronze_cnt;

    country(int n, int gold, int silver, int bronze)
        : num(n), gold_cnt(gold), silver_cnt(silver), bronze_cnt(bronze){}
};

bool cmp(country a, country b){
    if(a.gold_cnt == b.gold_cnt){
        if(a.silver_cnt == b.silver_cnt){
            return a.bronze_cnt > b.bronze_cnt;
        }
        return a.silver_cnt > b.silver_cnt;
    }
    return a.gold_cnt > b.gold_cnt;
}

int main(){
    int n, k;

    cin >> n >> k;
    vector<country> countries;
    for(int i=0; i<n; i++){
        int num, gold, silver, bronze;
        cin >> num >> gold >> silver >> bronze;
        countries.push_back(country(num, gold, silver, bronze));
    }

    sort(countries.begin(), countries.end(), cmp);

    // 순위 계산
    vector<int> rank(n + 1);
    int current_rank = 1;

    for (int i = 0; i < n; i++) {
        if (i > 0 && countries[i].gold_cnt == countries[i - 1].gold_cnt &&
            countries[i].silver_cnt == countries[i - 1].silver_cnt &&
            countries[i].bronze_cnt == countries[i - 1].bronze_cnt) {
            rank[countries[i].num] = current_rank;
        } else {
            current_rank = i + 1;
            rank[countries[i].num] = current_rank;
        }
    }
    cout << rank[k] << endl;
}