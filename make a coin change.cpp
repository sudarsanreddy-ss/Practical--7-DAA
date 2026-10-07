#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int coins[] = {1, 2, 5, 10};
    int n = 4;
    int amount = 12;

    int dp[100];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        dp[i] = 999999;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    cout << "Minimum coins required = " << dp[amount] << endl;

    return 0;
}
