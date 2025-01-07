#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cheese {
    int volume;
    int price;
};

int getMaxCheesePrice(int bagVolume, vector<Cheese>& cheeses) {
    int n = cheeses.size();
    vector<vector<int>> dp(n + 1, vector<int>(bagVolume + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= bagVolume; j++) {
            if (cheeses[i - 1].volume <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cheeses[i - 1].volume] + cheeses[i - 1].price);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][bagVolume];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, bagVolume;
        cin >> n >> bagVolume;

        vector<Cheese> cheeses(n);
        for (int i = 0; i < n; i++) {
            cin >> cheeses[i].volume >> cheeses[i].price;
        }

        int maxCheesePrice = getMaxCheesePrice(bagVolume, cheeses);
        cout << maxCheesePrice << endl;
    }

    return 0;
}
