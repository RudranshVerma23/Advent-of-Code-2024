#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int indexBinarySearch(vector<pair<int,int>> v, int x, int y){
    int l = 0, r = v.size()-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(v[mid].first == x && v[mid].second == y){
            return mid;
        }
        else if(v[mid].first < x || (v[mid].first == x && v[mid].second < y)){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}

int main(){
    ifstream MyReadFile("input.txt");
    string text;
    vector<pair<int,int>> v;
    while (getline (MyReadFile, text) && text.length() == 5 && text[2] == '|'){
        string temp = "";
        temp = temp + text[0] + text[1];
        int x = stoi(temp);
        temp = "";
        temp = temp + text[3] + text[4];
        int y = stoi(temp);
        v.push_back({x,y});
    } 
    sort(v.begin(),v.end(),cmp);
    int ans1 = 0, ans2 = 0;
    while(getline(MyReadFile,text)){
        int n = text.length();
        vector<int> a;
        int ind = 0,temp;
        string str;
        while(text[ind] != ','){
            str = str + text[ind];
            ind++;
        }
        temp = stoi(str);
        a.push_back(temp);
        ind++;
        str = "";
        bool check = true;
        int middle;
        while(ind < n){
            int x;
            while(text[ind]!=',' && ind<n){
                str = str + text[ind];
                ind++;
            }
            x = stoi(str);
            a.push_back(x);
            int y = indexBinarySearch(v,temp,x);
            if(y==-1) {check = false;}
            if(ind == n/2 + 1) {middle = x;}
            temp = x;
            str = "";
            ind++;
        }
        if(check) ans1 += middle;
        else{
            n = a.size();
            for(int i = 1; i < n; i++){
                ind = i-1;
                int t = indexBinarySearch(v,a[ind],a[i]);
                while(t==-1){
                    ind--;
                    if(ind<0) break;
                    t = indexBinarySearch(v,a[ind],a[i]);
                }
                int x = a[i];
                a.erase(a.begin()+i);
                a.insert(a.begin()+ind+1, x);
            }
            ans2 += a[n/2];
        }
    }
    cout << ans1;
}