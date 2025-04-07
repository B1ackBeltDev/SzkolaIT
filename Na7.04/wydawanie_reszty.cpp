#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int k = 7;
    int n = 4;
    vector<int> v = {2, 1, 6, 1};

    vector<int> dp(k+1, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = k; j >= v[i]; j--)
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
    
    for(int i = 0; i <= k; i++)
        cout << (dp[i] != INF ? dp[i] : -1) << ' ';
    cout << '\n';
}