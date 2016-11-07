#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

string ptrn;
int idx;
vector<int>numbers;
vector<string>words;

void print(){
    int j = 0;
    for (int i = 0;i<ptrn.size();i++){
        if (ptrn[i] == '#') cout<<words[idx];
        else cout<<numbers[j++];
    }
    cout<<'\n';
}
void solve(int depth,int limit){
    if (depth >= limit) {
        print();
        return;
    }
    for (int i = 0;i<=9;i++){
        numbers.push_back(i);
        solve(depth+1,limit);
        numbers.pop_back();
    }
}

int zeroCount(){
    int cnt = 0;
    for (int i = 0;i<ptrn.size();i++)
        if (ptrn[i] == '0') cnt++;
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    int n,m; string word, pattern;
    while (cin >> n){
        for (int i = 0;i < n;i++) {
            cin >> word;
            words.push_back(word);
        }
        cin >> m;
        for (int i = 0;i< m; i++) {
            int cnt = 0;
            cin >> pattern;
            cout<<"--"<<'\n';
            ptrn = pattern;
            for (int i = 0; i < n; i++){
                idx = i;
                solve(0,zeroCount());
            }
        }
        words.clear();
        numbers.clear(); 
    }
    
}