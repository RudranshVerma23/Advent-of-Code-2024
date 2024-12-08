#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream MyReadFile("input.txt");
    vector<string> s;
    string temp;
    int x=0,y=0; char curr = 'N';
    while(getline(MyReadFile,temp)){
        s.push_back(temp);
    }
    int n = s.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '^'){
                x = i;
                y = j;
                s[x][y] = 'X';
            }
        }
    }
    
    while(1){
        if(curr == 'N'){
            if(x==0){
                break;
            }
            else if(s[x-1][y] == '#'){
                curr = 'E';
                continue;
            }
            else {
                x--;
            }
        }
        else if(curr == 'E'){
            if(y==n-1){
                break;
            }
            else if(s[x][y+1] == '#'){
                curr = 'S';
                continue;
            }
            else {
                y++;
            }
        }
        else if(curr == 'S'){
            if(x==n-1){
                break;
            }
            else if(s[x+1][y] == '#'){
                curr = 'W';
                continue;
            }
            else {
                x++;
            }
        }
        else if(curr == 'W'){
            if(y==0){
                break;
            }
            else if(s[x][y-1] == '#'){
                curr = 'N';
                continue;
            }
            else {
                y--;
            }
        }
        s[x][y] = 'X';
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == 'X'){
                ans++;
            }
        }
    }
    cout << ans;
}