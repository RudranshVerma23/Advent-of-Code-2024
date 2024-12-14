#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream Myfileinput("input.txt");
    string txt;
    vector<pair<int,int>> p,v;
    while(getline(Myfileinput, txt)){
        string t1,t2;
        string s;
        stringstream ss(txt);
        while(getline(ss, s, ' ')){
            if(t1 == ""){
                t1 = s;
            }
            else{
                t2 = s;
            }
        }
        for(int i = 0; i < 2; i++){
            t1.erase(t1.begin());
            t2.erase(t2.begin());
        }
        pair<int,int> temp;
        bool r = true;
        stringstream s1(t1), s2(t2);
        while(getline(s1, s, ',')){
            if(r){
                temp.first = stoi(s);
                r = false;
            }
            else{
                temp.second = stoi(s);
            }
        }
        r = true;
        p.push_back(temp);
        while(getline(s2, s, ',')){
            if(r){
                temp.first = stoi(s);
                r = false;
            }
            else{
                temp.second = stoi(s);
            }
        }
        v.push_back(temp);
    }
    auto cpy = p;
    int n = p.size();
    int num = 100;
    int x = 101, y = 103;
    int one=0,two=0,three=0,four=0;
    for(int i = 0; i < n; i++){
        cpy[i].first += num * v[i].first;
        cpy[i].second += num * v[i].second;
        while(cpy[i].first < 0){
            cpy[i].first += 100*x;
        }
        while(cpy[i].second < 0){
            cpy[i].second += 100*y;
        }
        cpy[i].first %= x;
        cpy[i].second %= y;
        if(cpy[i].first == x/2 || cpy[i].second == y/2){
            continue;
        }
        else if(cpy[i].first < x/2 && cpy[i].second < y/2){
            one++;
        }
        else if(cpy[i].first < x/2 && cpy[i].second > y/2){
            two++;
        }
        else if(cpy[i].first > x/2 && cpy[i].second < y/2){
            three++;
        }
        else{
            four++;
        }
    }
    int ans = one*two*three*four;
    cout << ans << endl;
}