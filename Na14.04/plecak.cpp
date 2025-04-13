#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Podaj pojemnosc plecaka: ";
    int W;
    cin >> W;

    cout << "Podaj ilosc przedmiotow: ";
    int n;
    cin >> n;

    vector<int> dp(W+1, 0);

    cout << "Podaj przedmioty w formacie (waga, wartosc) oddzielone bialymi znakami: " << endl;
    for(int i = 0; i < n; i++){
        int w, c;
        cin >> w >> c;
        for(int j = W; j >= w; j--)
            dp[j] = max(dp[j], dp[j-w] + c);
    }

    cout << "Maksymalna osiagana ukradziona wartosc wynosi: " << dp[W] << endl;
}