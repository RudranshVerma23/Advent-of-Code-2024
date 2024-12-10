#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ifstream MyReadFile("input.txt");
    string text;
    getline(MyReadFile, text);
    vector<int> v;
    int n = text.size();
    int len = 0;
    int dp[n];
    for(int i = 0; i < n; i++){
        len += text[i] - '0';
        dp[i] = len;
        if(i%2){
            for(int j = 0; j < text[i] - '0'; j++){
                v.push_back(-1);
            }
        }
        else {
            for(int j = 0; j < text[i] - '0'; j++){
                v.push_back(i/2);
            }
        }
    }
    for(int i = n-1; i >=2; i-=2){
        int freq = text[i] - '0';
        int start = -1;
        for(int j = 0; j < dp[i-1]; j++){
            if(v[j]!=-1){
                start = -1;
            }
            else{
                start = j;
                for(int k = 0; k < freq; k++){
                    if(j>=dp[i-1]){
                        start = -1;
                        break;
                    }
                    if(v[j++]!=-1){
                        start = -1;
                        break;
                    }
                }
                j--;
                if(start!=-1){
                    for(int k = 0; k < freq; k++){
                        swap(v[start+k], v[dp[i-1]+k]);
                    }
                    break;
                }
            }
        }
    }
    int checkSum = 0;
    for(int i = 0; i < len; i++){
        if(v[i]==-1){continue;}
        checkSum += i*v[i];
    }
    cout << checkSum;
}