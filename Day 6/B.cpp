#include<bits/stdc++.h>
using namespace std;

int check(vector<string>& s, int x, int y, int n){
    char curr = 'N';
    int index = 1;
    while(true){
        if(curr == 'N'){
            if(x==0){
                return 0;
            }
            else if(s[x-1][y] == '#'){
                curr = 'E';
                continue;
            }
            else {
                index++;
                x--;
            }
        }
        else if(curr == 'E'){
            if(y==n-1){
                return 0;
            }
            else if(s[x][y+1] == '#'){
                curr = 'S';
                continue;
            }
            else {
                index++;
                y++;
            }
        }
        else if(curr == 'S'){
            if(x==n-1){
                return 0;
            }
            else if(s[x+1][y] == '#'){
                curr = 'W';
                continue;
            }
            else {
                index++;
                x++;
            }
        }
        else if(curr == 'W'){
            if(y==0){
                return 0;
            }
            else if(s[x][y-1] == '#'){
                curr = 'N';
                continue;
            }
            else {
                index++;
                y--;
            }
        }
        if(index == 2*n*n){
            return 1;
        }
    }
    return 0;
}

int main(){
    ifstream MyReadFile("input.txt");
    vector<string> s;
    string temp;
    int x, y;
    while(getline(MyReadFile,temp)){
        s.push_back(temp);
    }
    int n = s.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '^'){
                x = i;
                y = j;
                s[x][y] = '.';
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==x && j==y){
                continue;
            }
            if(s[i][j] == '.'){
                vector<string> temp = s;
                temp[i][j] = '#';
                ans += check(temp,x,y,n);
            }
        }
    }
    cout << ans;
}