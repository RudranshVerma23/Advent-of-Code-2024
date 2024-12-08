#include<bits/stdc++.h>
using namespace std;
int main(){
    fstream file;
    file.open("input.txt", ios::in);
    vector<string> s;
    string line;
    while (getline(file, line)) {
        s.push_back(line);
    }
    file.close();
    int n = s.size();
    int ans = 0;
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < n-1; j++){
            if(s[i][j]=='A'){
                if((s[i-1][j-1]=='M' && s[i+1][j+1]=='S') || (s[i-1][j-1]=='S' && s[i+1][j+1]=='M')){
                    if((s[i-1][j+1]=='M' && s[i+1][j-1]=='S') || (s[i-1][j+1]=='S' && s[i+1][j-1]=='M')){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
}