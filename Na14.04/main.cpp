#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int P = 31;
const int MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    const int n = s.size();

    vector<int> pref_hash(n);
    vector<int> pows(n);

    {
        pref_hash[0] = s[0] - 'a' + 1;
        pows[0] = 1;
        for(int i = 1; i < n; i++){
            pref_hash[i] = ((ll)pref_hash[i-1] * P) % MOD;
            pref_hash[i] = ((ll)pref_hash[i] + s[i] - 'a' + 1) % MOD;
            pows[i] = ((ll)pows[i-1] * P) % MOD;
        }
    }

    int t = 1;
    // cin >> t;

    while(t--){
        string p;
        cin >> p;

        int m = p.size();

        int hash = p[0] - 'a' + 1;
        for(int i = 1; i < m; i++){
            hash = ((ll)hash * P) % MOD;
            hash = ((ll)hash + p[i] - 'a' + 1) % MOD;
        }

        bool ok = false;
        for(int i = m-1; i < n && !ok; i++){
            int s_hash = pref_hash[i];
            if(i - m >= 0)
                s_hash = ((ll)(((ll)s_hash - ((ll)pref_hash[i-m] * pows[m])%MOD)%MOD)+MOD)%MOD;
            
            if(s_hash == hash){
                cout << "YES\n";
                ok = true;
            }
        }

        if(!ok)
            cout << "NO\n";
    }


}