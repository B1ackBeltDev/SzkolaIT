#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n, vector<int> v, int k, bool limited){
    int kbegin = k;

    sort(v.begin(), v.end());
    
    vector<int> ans;
    for(int i = n-1; i >= 0; i--){
        if(limited){
            if(k-v[i] >= 0){
                ans.push_back(v[i]);
                k -= v[i];
            }
        }else{
            while(k-v[i] >= 0){
                ans.push_back(v[i]);
                k -= v[i];
            }
        }
    }

    if(k != 0) cout << "Nie da rady!" << endl;
    else{
        cout << kbegin << " = " << ans[0];
        for(int i = 1; i < ans.size(); i++) cout << " + " << ans[i];
        cout << endl;
    }
}

int main(){
    cout << "Podaj liczbe dostepnych monet: ";
    int n;
    cin >> n;

    cout << "Podaj dostepne nominaly: ";
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    cout << "Podaj kwote do wydania: ";
    int k;
    cin >> k;

    cout << "Gdy jest ograniczona ilosc nominalow:" << endl;
    solve(n, v, k, true);

    cout << "Gdy jest nieograniczona ilosc nominalow:" << endl;
    solve(n, v, k, false);
}