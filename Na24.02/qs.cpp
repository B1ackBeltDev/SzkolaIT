#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int gen(int l, int r){return uniform_int_distribution<int>(l, r)(rng);}

void get_input(int &n, int &k, vector<int> &v){
    cout << "Podaj dlugosc ciagu: ";
    cin >> n;

    cout << "Podaj kolejne elementu ciagu: ";
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    cout << "Podaj, ktory najmniejszy element chcesz uzyskac: [1, " << n << "] ";
    cin >> k;
    
    k--;
    assert(0 <= k && k < n);
}

int split(vector<int> &v, int left, int right){
    int pivot_idx = gen(left, right);
    int pivot_val = v[pivot_idx];
    swap(v[pivot_idx], v[right]);
    int pt = left;
    for(int i = left; i < right; i++){
        if(v[i] < pivot_val){
            swap(v[pt], v[i]);
            pt++;
        }
    }
    swap(v[right], v[pt]);
    return pt;
}

int quick_select(vector<int> &v, int n, int k){
    int left = 0;
    int right = n-1;
    while(left != right){
        int pivot = split(v, left, right);
        if(k == pivot) return v[k];
        else if(k < pivot) right = pivot - 1;
        else left = pivot + 1;
    }
    return v[left];
}

int main(){
    int n, k;
    vector<int> v;

    get_input(n, k, v);

    cout << "K-ty najmniejszy element to: " << quick_select(v, n, k) << endl;
}