#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ifstream myfile("input.txt");
    string txt;
    vector<string> map;
    int ind = 0,x,y;
    while(getline(myfile, txt)){
        if(txt == "") {break;}
        if(txt.find('@') != string::npos){
            x = ind,  y = txt.find('@');
        }
        ind++;
        map.push_back(txt);
    }
    // instructions
    while(getline(myfile, txt)){
        for(auto i: txt){
            int xc = x, yc = y;
            if(i == '^'){
                while(map[xc][yc]=='O' || map[xc][yc]=='@') {xc--;}
                if(map[xc][yc] == '.'){
                    map[xc][yc] = map[xc+1][yc];
                    map[x][y] = '.';
                    x--;
                    map[x][y] = '@';
                }
            }
            else if(i == 'v'){
                while(map[xc][yc]=='O' || map[xc][yc]=='@') {xc++;}
                if(map[xc][yc] == '.'){
                    map[xc][yc] = map[xc-1][yc];
                    map[x][y] = '.';
                    x++;
                    map[x][y] = '@';
                }
            }
            else if(i == '<'){
                while(map[xc][yc]=='O' || map[xc][yc]=='@') {yc--;}
                if(map[xc][yc] == '.'){
                    map[xc][yc] = map[xc][yc+1];
                    map[x][y] = '.';
                    y--;
                    map[x][y] = '@';
                }
            }
            else if(i == '>'){
                while(map[xc][yc]=='O' || map[xc][yc]=='@') {yc++;}
                if(map[xc][yc] == '.'){
                    map[xc][yc] = map[xc][yc-1];
                    map[x][y] = '.';
                    y++;
                    map[x][y] = '@';
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] == 'O'){
                ans += 100*i + j;
            }
        }
    }
    cout << ans;
}