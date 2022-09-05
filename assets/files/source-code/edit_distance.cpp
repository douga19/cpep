#include <bits/stdc++.h>

using namespace std;

int main () {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    int dp[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = max(n, m);
        }
    }

    /**
     dp[i][j] = minimum edit distance between s1[0,i] and s2[0,j]
     - insertion : the last entry of s1 is empty then
            dp[i][j] = dp[i][j-1] + 1
     - deletion : the last entry of s2 is empty then
            dp[i][j] = dp[i-1][j] + 1
     - substitution : the last entry are have both a char
            if s1[i] == s2[j] (nothing to be done) then :
            dp[i][j] = dp[i-1][j-1]
            otherwise we have a substitution
            dp[i][j] = dp[i-1][j-1] + 1
     We take the min of those 3

     Base cases:
     dp[0][j] = j -> inserting j chars
     dp[i][0] = i -> deleting i chars
    */

    for (int j = 0; j < m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 0; i < n; ++i) {
        dp[i][0] = i;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            int ins = dp[i][j-1] + 1;
            int del = dp[i-1][j] + 1;
            int sub;
            if (s1[i] == s2[j]) {
                sub = dp[i-1][j-1];
            } else {
                sub = dp[i-1][j-1] + 1;
            }
            dp[i][j] = min(ins, min(del, sub));
            cout << dp[i][j] << " ";
        }
        printf("\n");
    }

    printf("%d\n", dp[n-1][m-1]);

    return 0;
}
