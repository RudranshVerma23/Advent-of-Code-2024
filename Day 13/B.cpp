#include<bits/stdc++.h>
using namespace std;
#define int long long
// same as in A
// This is becaue (10000000000000 + rx)/(10000000000000+ry) is too small to be equal to ax/ay or bx/by
// Hence there wont be any possibility of infinite solutions.
int32_t main(){
    ifstream MyReadFile("input.txt");
    vector<string> v;
    string text;
    while(getline(MyReadFile, text)){
        v.push_back(text);
    }
    v.push_back("");
    int n = v.size();
    int ans = 0;
    for(int i = 0; i < n/4; i++){
        int rx = 10000000000000,ry = rx;
        int ax,ay,bx,by;
        int ind = v[0].find('X');
        ax = stoi(v[0].substr(ind+2, ','));
        ind = v[0].find('Y');
        ay = stoi(v[0].substr(ind+2));

        ind = v[1].find('X');
        bx = stoi(v[1].substr(ind+2, ','));
        ind = v[1].find('Y');
        by = stoi(v[1].substr(ind+2));

        ind = v[2].find('X');
        rx += stoi(v[2].substr(ind+2, ','));
        ind = v[2].find('Y');
        ry += stoi(v[2].substr(ind+2));

        v.erase(v.begin(), v.begin()+4);
        if(ax*by == ay*bx){
            if(ax*rx == ay*ry || bx*rx == by*ry){
                continue;
            }
            else {
                int mini = 10000;
                for(int i = 1; i <= 100; i++){
                    if((rx-i)%ax == 0){
                        if((rx-i)/ax > 0){
                            mini = min(mini,3*(rx-i)/ax + i);
                        }
                    }
                }
                if(mini==1000) {continue;}
                else ans += mini;
            }
        }
        else {
            int d1 = -ax*by + ay*bx;
            int d2 = ry*bx - rx*by;
            int d3 = ay*rx - ax*ry;
            if(d2%d1 != 0 || d3%d1 != 0){
                continue;
            }
            if(d2/d1 < 0 || d3/d1 < 0){
                continue;
            }
            ans += 3*d2/d1 + d3/d1;
        }
    }
    cout << ans;
}