#include <bits/stdc++.h>
using namespace std;
#define ll long long

int op(ll a, ll b){
    for(int i = 0; i < b; i++){
        a /= 3;
    }
    return a%3;
}

int32_t main () {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    ll ans = 0;
    while (getline(file, line)) {
        ll head;
        string temp = "";
        ll index = 0;
        while(line[index] != ':') {
            temp += line[index];
            index++;
        }
        head = stoll(temp);
        index += 2;
        temp = "";
        vector<ll> v;
        while(index < line.size()) {
            if (line[index] == ' ') {
                v.push_back(stoll(temp));
                temp = "";
            } else {
                temp += line[index];
            }
            index++;
        }
        v.push_back(stoll(temp));
        ll n = v.size();
        //Using concept of bitmasking, here 3 operations possible (+,*,||)
        for(ll i = 0; i < (pow(3,n-1)); i++) {
            ll prim = v[0];
            for(ll j = 0; j < n-1; j++) {
                int t = op(i,j);
                if(t==0){
                    prim += v[j+1];
                } else if(t==1){
                    prim *= v[j+1];
                } else {
                    prim = prim*pow(10,(int)log10(v[j+1])+1)+v[j+1];
                    // concatenation of prim and v[j+1]
                }
            }
            if(prim == head) {
                ans += head;
                break;
            }
        }
    }
    file.close();
    cout << ans;
}