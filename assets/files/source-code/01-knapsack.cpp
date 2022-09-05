/**
    input:
    4 10
    10 40 30 50
    5 4 6 3

    output:
    90 (40 + 50) and (4 + 3)
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, cap;
    cin >> n >> cap;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    vector<int> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];

    int dp[n+1][cap+1];

    /**
        dp[i][j] = solution by selecting among 0,..,ith item st total weigth <= j
        -- then
        dp[i][j] =
        if ith is taken : dp[i][j] = vals[i] + dp[i-1][j-w[i]] (1)
        if ith is not taken : dp[i][j] = dp[i-1][j] (2)
        since we maximize the capacity so dp[i][j] = max((1), (2))
        -- but we need that j-w[i] >=0 then
        if (w[i] <= j) ok
        else dp[i][j] = dp[i-1][j]
    */

    // 0 cap : first line = 0;
    for (int j = 0; j <= cap; ++j) dp[0][j] = 0;
    // 0 items : first col = 0;
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= cap; ++j) {
            if (w[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], vals[i-1] + dp[i-1][j - w[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][cap] << "\n";
    cout << "Selected items are : \n";
    while (n > 0) {
        if (dp[n][cap] != dp[n-1][cap]) {
            cout << "Item: " << n << " value: " << vals[n-1] << " weigth: " << w[n-1] << endl;
            cap = cap - w[n-1];
        }
        n--;
    }
    return 0;
}
