#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    set<int> s;
    multiset<int> ms1,ms2;
    int n = 1000; // number of input lines given
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        s.insert(x);
        ms1.insert(x);
        ms2.insert(y);
    }
    int score = 0;
    for (auto i : s) {
        score += i*ms1.count(i)*ms2.count(i);
    }
    cout << score;
}