#include <iostream>
using namespace std;

int main(){
    constexpr int n = 5;
    constexpr int k = 10;
    int w[n] = {2, 3, 3, 1, 1};
    int v[n] = {3, 7, 6, 1, 2};
    int c[n] = {1, 2, 1, 1, 1};

    int dp[k+1][n+1] = {0};
    for(int i = 1; i <= k; i++){
        int which = -1;
        dp[i][0] = dp[i-1][0];
        for(int j = 0; j < n; j++){
            if(i - w[j] < 0 || dp[i-w[j]][j+1] == c[j])
                continue;
            if(dp[i-w[j]][0] + v[j] > dp[i][0]){
                dp[i][0] = dp[i-w[j]][0] + v[j];
                which = j;
            }
        }
        if(which == -1)
            memcpy(&dp[i][1], &dp[i-1][1], n * sizeof(int));
        else{
            memcpy(&dp[i][1], &dp[i-w[which]][1], n * sizeof(int));
            dp[i][which+1]++;
        }
    }

    cout << "Maksymalna wartosc: " << dp[k][0] << endl;
    cout << "Wykorzystane przedmioty: " << endl;
    for(int i = 0; i < n; i++)
        cout << i << " - " << dp[k][i+1] << endl;

    return 0;
}