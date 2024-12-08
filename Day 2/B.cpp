#include <bits/stdc++.h>
using namespace std;

int check(int* arr, int n){
    if(n == 1) return 1;
    else {
        if(arr[0]>arr[1] && arr[0] - arr[1]<=3){
            for(int j = 2; j < n; j++){
                if(arr[j-1] <= arr[j] || arr[j-1] - arr[j] > 3){
                    return 0;
                }
            }
            return 1;
        }
        else if(arr[0]<arr[1] && arr[1] - arr[0]<=3){
            for(int j = 2; j < n; j++){
                if(arr[j-1] >= arr[j] || arr[j] - arr[j-1] > 3){
                    return 0;
                }
            }
            return 1;
        }
        else return 0;
    }
}

int main(){
    int ans = 0;
    int n = 1000; // number of lines
    for(int i = 0; i < n; i++){
        string s;
        getline(cin,s);
        vector<string> v;
        string temp = "";
        for(int j = 0; j < s.size(); j++){
            if(s[j] == ' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp += s[j];
            }
            if(j == s.size()-1){
                v.push_back(temp);
            }
        }
        int arr[v.size()];
        for(int j = 0; j < v.size(); j++){
            arr[j] = stoi(v[j]);
        }
        
        if(check(arr,v.size())){
            ans++;
        }
        else {
            for(int j = 0; j < v.size(); j++){
                int b[v.size()-1];
                int ind = 0;
                for(int k = 0; k < v.size(); k++){
                    if(k == j) continue;
                    else {
                        b[ind] = arr[k];
                        ind++;
                    }
                }
                if(check(b, v.size()-1)){
                    ans++;
                    cout << 1 << endl;
                    break;
                }
            }
        }

    }
    cout << ans;
}