#include <iostream>
#include <string>
using namespace std;

// 문자열 뒤집기 함수
string reverse_str(string data, int start, int end) {
    while (start < end) {
        swap(data[start], data[end]);
        start++;
        end--;
    }
    return data;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string data;
        int n;

        cin >> n >> data;

        int i = n - 2;
        while (i >= 0 && data[i] >= data[i+1]) i--;

        if (i == -1) {
            data = reverse_str(data, 0, n-1);
            cout << data << endl;
            continue;
        }

        int j = n - 1;
        while(data[i] >= data[j]) j--;

        swap(data[i], data[j]);

        data = reverse_str(data, i+1, n-1);

        cout << data << endl;
    }

    return 0;
}
