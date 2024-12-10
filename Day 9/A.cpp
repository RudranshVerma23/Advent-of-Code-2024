#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ifstream MyReadFile("input.txt");
    string text;
    getline(MyReadFile, text);
    int n = text.size();

    /*
    My first approach was to use a stack to 
    keep track of the current position and 
    the current index of the number we are looking for
    without actually expanding everything.
    This approach is unfavorable for second part though.
    */

    /*
    int sum = 0;    
    int back = n-1, backfreq = text[back]-'0';
    int curr = 0;
    for(int i = 0; i < n; i++){
        if(text[i]=='.'){ break;}
        if(i==back){
            while(backfreq>0){
                sum += (curr++)*back/2;
                backfreq--;
            }
            break;
        }
        if((i&1)==0){
            for(int j = 0; j < text[i]-'0'; j++){
                sum += (curr++)*i/2;
            }
        }
        else{
            int space = text[i]-'0';
            for(int j = 0; j < space; j++){
                if(backfreq == 0){
                    if(back-1==i){break;}
                    text[back--] = '.';
                    text[back--] = '.';
                    backfreq = text[back]-'0';
                }
                sum += (curr++)*back/2;
                backfreq--;
            }
        }
    }
    cout << sum;
    */
    //Second approach is to expand everything directly.
    
    vector<int> v;
    int len = 0;
    for(int i = 0; i < n; i++){
        len += text[i] - '0';
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
    int front = 0, back = len-1;
    while(front<back){
        if(v[front]!=-1){front++; continue;}
        if(v[back]==-1){back--; continue;}
        swap(v[front], v[back]);
        front++; back--;
    }
    int checkSum = 0;
    for(int i = 0; i <= front; i++){
        if(v[i]==-1){continue;}
        checkSum += i*v[i];
    }
    cout << checkSum;
}