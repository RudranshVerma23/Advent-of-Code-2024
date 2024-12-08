#include <bits/stdc++.h>
using namespace std;
int check(int x, int n) {
    if(x < 0 || x >= n) {
        return 0;
    }
    return 1;
}
int main () {
    fstream file;
    file.open("input.txt", ios::in);
    vector<string> v;
    string line;
    while (getline(file, line)) {
        v.push_back(line);
    }
    file.close();
    int n = v.size();
    vector<string> v2 = vector<string>(n, string(n, '.'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j]=='.') {
                continue;
            }
            vector<pair<int, int>> temp;
            for(int l = i; l < n; l++){
                for(int m = 0; m < n; m++){
                    if(v[l][m]==v[i][j]) {
                        temp.push_back({l, m});
                    }
                }
            }
            if(temp.size() > 1) {
                int t = temp.size();
                for(int l = 0; l < t; l++){
                    for(int m = l+1; m < t; m++){
                        int cx = (temp[l].first - temp[m].first);
                        int cy = (temp[l].second - temp[m].second);
                        int ind = 1;
                        while(1){
                            if(!check(temp[l].first + ind*cx, n) || !check(temp[l].second + ind*cy, n)) {
                                break;
                            }
                            v2[temp[l].first + ind*cx][temp[l].second + ind*cy] = '#';
                            ind++;
                        }
                        ind = 0;
                        while(1){
                            if(!check(temp[m].first - ind*cx, n) || !check(temp[m].second - ind*cy, n)) {
                                break;
                            }
                            v2[temp[m].first - ind*cx][temp[m].second - ind*cy] = '#';
                            ind++;
                        }
                    }
                    v[temp[l].first][temp[l].second] = '.';
                    v2[temp[l].first][temp[l].second] = '#';
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v2[i][j] == '#') {
                ans++;
            }
        }
    }
    cout << ans << endl;
}