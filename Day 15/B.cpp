#include<bits/stdc++.h>
using namespace std;

int check(int x, int y, vector<string> &map, vector<string>&cpy, int dir){
    // dir = -1 for up and dir = 1 for down
    cpy[x][y] = '0';
    if(map[x+dir][y] == '.') {return 1;}
    else if(map[x+dir][y] == '#') {return 0;}
    else if(cpy[x+dir][y]!='0'){
        if(map[x+dir][y]=='['){
            cpy[x+dir][y+1] = '0';
            return (check(x+dir, y, map, cpy, dir) && check(x+dir, y+1, map, cpy, dir));
        }
        else if(map[x+dir][y]==']'){
            
            cpy[x+dir][y-1] = '0';
            return (check(x+dir, y, map, cpy, dir) && check(x+dir, y-1, map, cpy, dir));
        }
    }
    return 1;
}
void move(vector<string> &map, vector<string>&cpy, int dir){
    if(dir == -1){
        for(int i = 0; i < map.size(); i++){
            for(int j = 0; j < map[i].size(); j++){
                if(map[i][j] == '@') {
                    map[i-1][j] = '@';
                    map[i][j] = '.';
                    return;
                }
                if(cpy[i][j] == '0'){
                    map[i-1][j] = map[i][j];
                    map[i][j] = '.';
                }
            }
        }
    }
    else{
        for(int i = map.size()-1; i >= 0; i--){
            for(int j = 0; j < map[i].size(); j++){
                if(map[i][j] == '@') {
                    map[i+1][j] = '@';
                    map[i][j] = '.';
                    return;
                }
                if(cpy[i][j] == '0'){
                    map[i+1][j] = map[i][j];
                    map[i][j] = '.';
                }
            }
        }
    }    
}

int32_t main(){
    ifstream myfile("input.txt");
    string txt;
    vector<string> map;
    int ind = 0,x=6,y=6;
    while(getline(myfile, txt)){
        if(txt == "") {break;}
        string temp = "";
        for(int i = 0; i < txt.size(); i++){
            if (txt[i] == 'O') {temp += "[]";}
            else if (txt[i] == '@') {temp += "@.";}
            else if(txt[i]=='#') {temp += "##";}
            else temp += "..";
        }
        map.push_back(temp);
        if(temp.find('@') != string::npos){
            x = ind,  y = temp.find('@');
        }
        ind++;
    }
    // instructions
    while(getline(myfile, txt)){
        for(auto i: txt){
            int xc = x, yc = y;
            auto cpy = map;
            if(i == '^'){
                if(check(xc, yc, map, cpy, -1)){
                    move(map, cpy, -1);
                    x--;
                }
            }
            else if(i == 'v'){
                if(check(xc, yc, map, cpy, 1)){
                    move(map, cpy, 1);
                    x++;
                }
            }
            else if(i == '<'){
                while(map[xc][yc]!='#' && map[xc][yc]!='.') {yc--;}
                if(map[xc][yc] == '.'){
                    while(yc!=y){
                        map[xc][yc] = map[xc][yc+1];
                        yc++;
                    }
                    map[xc][yc] = '.';
                    y--;
                }
            }
            else if(i == '>'){
                while(map[xc][yc]!='#' && map[xc][yc]!='.') {yc++;}
                if(map[xc][yc] == '.'){
                    while(yc!=y){
                        map[xc][yc] = map[xc][yc-1];
                        yc--;
                    }
                    map[xc][yc] = '.';
                    y++;
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] == '['){
                ans += 100*i + j;
            }
        }
    }
    cout << ans;
}