#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    // Bruteforce (Better approach in B)
    ifstream MyReadFile("input.txt");
    string text;
    getline(MyReadFile, text);
    vector<int> v;
    stringstream ss(text);
    while(getline(ss, text, ' ')){
        v.push_back(stoi(text));
    }
    int n = v.size();
    for(int tt = 0; tt < 25; tt++){
        for(int i = n-1; i>=0; i--){
            if(v[i]==0) {v[i]=1; continue;}
            string temp = to_string(v[i]);
            if(temp.size()%2 == 0){
                string temp2 = "";
                int t = temp.size();
                for(int j = 0; j < t/2; j++){
                    temp2 += temp[t/2];
                    temp.erase(temp.begin()+t/2);
                }
                v.erase(v.begin()+i);
                v.insert(v.begin()+i, stoi(temp2));
                v.insert(v.begin()+i, stoi(temp));
            }
            else{
                v[i] *= 2024;
            }
        }
        n = v.size();
    }
    cout << n;
}