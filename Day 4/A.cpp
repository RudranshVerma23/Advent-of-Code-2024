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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-3; j++){
            if(s[i].substr(j,4)=="XMAS" || s[i].substr(j,4)=="SAMX") {ans++;}
            if(s[j][i] == 'X' && s[j+1][i] == 'M' && s[j+2][i] == 'A' && s[j+3][i] == 'S') {ans++;}
            if(s[j][i] == 'S' && s[j+1][i] == 'A' && s[j+2][i] == 'M' && s[j+3][i] == 'X') {ans++;}
            if(i>=137) continue;
            if(s[i][j] == 'X' && s[i+1][j+1] == 'M' && s[i+2][j+2] == 'A' && s[i+3][j+3] == 'S') {ans++;}
            if(s[i][j] == 'S' && s[i+1][j+1] == 'A' && s[i+2][j+2] == 'M' && s[i+3][j+3] == 'X') {ans++;}
            if(s[i][j+3] == 'X' && s[i+1][j+2] == 'M' && s[i+2][j+1] == 'A' && s[i+3][j] == 'S') {ans++;}
            if(s[i][j+3] == 'S' && s[i+1][j+2] == 'A' && s[i+2][j+1] == 'M' && s[i+3][j] == 'X') {ans++;}
        }
    }
    cout << ans;
}