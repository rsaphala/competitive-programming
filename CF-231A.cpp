#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

#define endl '\n'
#define null NULL
#define fastIO ios_base::sync_with_stdio(0);
#define ll long long 

using namespace std;

int n,a,b,c;
vector<int>v;

bool solve(){
    int cnt = 0;
    for (int i : v){
        if (i == 1) cnt++;
    }
    if (cnt >= 2) return true;
    return false;
}

int main(){
    int cnt = 0;
    cin >> n;
    for (int i = 0;i<n;i++){
        cin >> a >> b >> c;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        if (solve()) cnt++;
        v.clear();
    }
    cout << cnt << endl;
}