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
                        if(check(temp[l].first + cx, n) && check(temp[l].second + cy, n)) {
                            v2[temp[l].first + cx][temp[l].second + cy] = '#';
                        }
                        if(check(temp[m].first - cx, n) && check(temp[m].second - cy, n)) {
                            v2[temp[m].first - cx][temp[m].second - cy] = '#';
                        }
                    }
                    v[temp[l].first][temp[l].second] = '.';
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