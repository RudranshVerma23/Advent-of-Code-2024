#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream MyReadFile("input.txt");
    vector<string> s;
    string text;
    while(getline(MyReadFile, text)){
        s.push_back(text);
    }
    int n = s.size();
    int score = 0;
    vector<pair<int,int> > dir = {{1,0},{0,1},{-1,0},{0,-1}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j]=='0'){
                int x = i, y = j;
                stack<pair<int,pair<int,int> > > st;
                // set<pair<int,int> > vis;
                st.push({0,{x,y}});
                while(!st.empty()){
                    pair<int,int> p = st.top().second;
                    int ind = st.top().first;
                    st.pop();
                    x = p.first;
                    y = p.second;
                    if(ind == 9){
                        // vis.insert({x,y});
                        score++;
                        continue;
                    }
                    for(auto d: dir){
                        int nx = x + d.first;
                        int ny = y + d.second;
                        if(nx>=0 && nx<n && ny>=0 && ny<n && s[nx][ny]==ind+'1'){
                            st.push({ind+1,{nx,ny}});
                        }
                    }
                }
            }
        }
    }
    cout<<score<<endl;
}