#include <bits/stdc++.h>
using namespace std;

int m5(vector<int> v, int begin, int end, int k){
    if(end - begin == 1)
        return v[begin];

    vector<int> medians;

    vector<int> temp;
    for(int i = begin; i < end; i += 5){
        temp.clear();
        for(int j = 0; j < 5; j++){
            if(i + j >= end)
                break;
            temp.push_back(v[i + j]);
        }
        sort(temp.begin(), temp.end());
        medians.push_back(temp[temp.size() / 2]);
    }

    int pivot;
    if(medians.size() <= 5){
        sort(medians.begin(), medians.end());
        pivot = medians[medians.size() / 2];
    }else
        pivot = m5(medians, 0, medians.size(), medians.size() / 2);

    int left = begin;
    int right = end - 1;
    int pivot_idx = -1;

    while(left < right){
        while(left < right && v[left] < pivot)
            left++;
        while(left < right && v[right] >= pivot)
            right--;
        if(left < right)
            swap(v[left], v[right]);
    }

    if(k - 1 < left)
        return m5(v, begin, left, k);
    else
        return m5(v, left, end, k);
}

int main(){
    int n = 10;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    for(int i = 1; i <= n; i++){
        random_shuffle(v.begin(), v.end());

        cout << "Should be " << i << " is " << m5(v, 0, n, i) << '\n';
    }
}