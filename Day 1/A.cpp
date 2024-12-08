#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    vector<int> v1,v2;
    int n = 1000; // number of input lines given
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        v1.push_back(x);
        v2.push_back(y);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int dist = 0;
    for (int i = 0; i < n; i++) {
        dist += abs(v1[i]-v2[i]);
    }
    cout << dist;
}