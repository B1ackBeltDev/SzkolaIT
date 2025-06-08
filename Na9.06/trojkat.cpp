#include <iostream>
using namespace std;

void move(int &id, bool from){
    if(from == 0)
        id--;
}

int main(){
    const int n = 3;
    int t[n][n] = {{3, 0, 0}, {5, 1, 0}, {44, 12, 60}};
    int dp[n][n];
    bool where[n][n] = {false};

    fill(&dp[0][0], &dp[0][0] + n * n, INT_MAX);

    dp[0][0] = t[0][0];
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < i + 1; j++){
            if(dp[i][j] + t[i+1][j] < dp[i+1][j]){
                dp[i+1][j] = dp[i][j] + t[i+1][j];
                where[i+1][j] = true;
            }
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + t[i+1][j+1]);
        }
    }

    int id = 0;
    for(int i = 1; i < n; i++)
        if(dp[n-1][i] < dp[n-1][id])
            id = i;

    cout << t[n-1][id] << ' ';
    move(id, where[n-1][id]);
    for(int i = n - 2; i >= 0; i--){
        cout << t[i][id] << ' ';
        move(id, where[i][id]);
    }
    cout << '\n';
}