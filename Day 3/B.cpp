#include<bits/stdc++.h>
using namespace std;
int main(){
    fstream file;
    file.open("input.txt", ios::in);
    int ans = 0;
    int done = 1;
    vector<string> v;
    string s;
    while (getline(file, s)) {
        int n = s.length();
        for(int j = 0; j < n; j++){
            if(s.substr(j,4) == "do()"){
                done = 1;
                j += 3;
            }
            else if (s.substr(j,7) == "don't()"){
                done = 0; j += 6;
            }
            else if(done){
                    if(s.substr(j,4) == "mul("){
                    j += 4;
                    string num1 = "",num2 = "";
                    int t1,t2;
                    int temp = 1;
                    while(s[j] != ','){
                        if(s[j] >= '0' && s[j] <= '9'){
                            num1 += s[j];
                            j++;
                        }
                        else {
                            temp = 0;
                            break;
                        }
                    }
                    if(temp==0) continue;
                    if(s[j] == ','){
                        j++;
                    }
                    else {
                        continue;
                    }
                    while(s[j] != ')'){
                        if(s[j] >= '0' && s[j] <= '9'){
                            num2 += s[j];
                            j++;
                        }
                        else {
                            temp = 0;
                            break;
                        }
                    }
                    if(temp==0) continue;
                    t1 = stoi(num1);
                    t2 = stoi(num2);
                    ans += t1*t2;
                }
            }
        }
    }
    file.close();
    for(int i = 0; i < 6; i++){
        
    }
    cout << ans;
}