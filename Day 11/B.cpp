#include<bits/stdc++.h>
using namespace std;
#define int long long
map<pair<int, int>, int> m;

int solve(int num, int times){
    if(m.find({num, times}) != m.end()){
        return m[{num, times}];
    }
    if(times == 0) {
        m[{num, times}] = 1;
        return 1;
    }
    if(num == 0){
        m[{num, times}] = solve(1, times-1);
        return m[{num, times}];
    }
    if(to_string(num).length()%2 == 0){
        string temp = to_string(num);
        string temp2 = temp.substr(temp.size()/2, temp.size()/2);
        temp = temp.substr(0, temp.size()/2);
        m[{num, times}] = solve(stoi(temp2), times-1) + solve(stoi(temp), times-1);
        return m[{num, times}];
    }
    else{
        m[{num, times}] = solve(num*2024, times-1);
        return m[{num, times}];
    }
    
}
int32_t main(){
    ifstream MyReadFile("input.txt");
    string text;
    getline(MyReadFile, text);
    vector<int> v;
    stringstream ss(text);
    while(getline(ss, text, ' ')){
        v.push_back(stoi(text));
    }
    
    int n = v.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += solve(v[i],75);
    }
    cout << ans;
}