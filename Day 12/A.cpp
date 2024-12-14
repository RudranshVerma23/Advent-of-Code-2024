#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ifstream MyReadFile("input.txt");
    vector<string> v;
    string text;
    while(getline(MyReadFile, text)){
        v.push_back(text);
    }
    vector<string> cpy = v;
    set<char> s;
    int n = v.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cpy[i][j] == '0'){
                continue;
            }
            int area = 0, peri = 0;
            stack<pair<int, int>> st;
            st.push({i, j});
            while(!st.empty()){
                pair<int,int> t = st.top();
                st.pop();
                int x = t.first, y = t.second;
                if(x < 0 || y < 0 || x >= n || y >= v[x].size() || cpy[x][y] != v[i][j]) {
                    continue;
                }
                cpy[x][y] = '0';
                area++;
                st.push({x+1, y});
                st.push({x-1, y});
                st.push({x, y+1});
                st.push({x, y-1});
                peri += 4;
                if(x+1 < n && v[x+1][y] == v[i][j]){
                    peri--;
                }
                if(x-1 >= 0 && v[x-1][y] == v[i][j]){
                    peri--;
                }
                if(y+1 < v[x].size() && v[x][y+1] == v[i][j]){
                    peri--;
                }
                if(y-1 >= 0 && v[x][y-1] == v[i][j]){
                    peri--;
                }
            }
            ans += area * peri;
            // cout << area << " " << peri << endl;
        }
    }
    cout << ans;
}