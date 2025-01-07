#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int kth_largest_sum(const vector<int>& nums, int k) {
    priority_queue<int, vector<int>, less<int>> min_heap;
    int total_sum = 0;

    for (int num : nums) {
        min_heap.push(num);

        // 힙의 크기가 k보다 크다면 가장 작은 값을 제거
        if (min_heap.size() > k) {
            min_heap.pop();
        }

        // 현재 k번째로 큰 값은 최소 힙의 루트에 있음
        total_sum += min_heap.top();
    }

    return total_sum;
}

int main(){

    vector<int> nums;

    for(int i=0; i<100; i++){
        nums.push_back(i);
    }

    int answer = kth_largest_sum(nums, 3);

    cout << answer << endl;
}