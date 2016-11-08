#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#define endl '\n'

using namespace std;


string input;
bool space;

void solve(string s,int depth){
    if (depth == input.size()){
        cout << s <<endl;
        return;
    }
    for (int i = 0;i<=s.size();i++){
        if (!i) solve(input[depth] + s, depth+1);
        else if (i == s.size()) solve(s + input[depth], depth+1);
        else solve(s.substr(0,i) + input[depth] + s.substr(i),depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    space = false;
    while (cin >> input){
        if (space) cout<<endl;
        space = true;
        solve("",0);
    }
}