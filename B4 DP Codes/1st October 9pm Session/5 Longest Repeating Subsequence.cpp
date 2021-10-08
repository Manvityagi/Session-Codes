/*
a1a2a3b1 ... example

LRS = LCS of equal strings with the condition that no indices are equal

*/
#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int LRS(string str, int i, int j)
{

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == 0 || j == 0)
        return dp[i][j] = 0;

    if (str[i - 1] == str[j - 1] && i != j)
        return dp[i][j] = LRS(str, i - 1, j - 1) + 1;

    return dp[i][j] = max(LRS(str, i, j - 1), LRS(str, i - 1, j));
}

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    memset(dp, -1, sizeof(dp));
    cout << LRS(str, len, len);

    return 0;
}