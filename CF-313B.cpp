#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#define endl '\n'

using namespace std;

int arr[100001];
string s;
int m,l,r;

void solve(){
    for (int i = 1;i<s.size();i++){
        if (s[i] == s[i-1]) arr[i] = arr[i-1]+1;
        else arr[i] = arr[i-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    memset (arr,0,sizeof(arr));
    cin >> s;
    solve();
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> l >> r;
        cout << arr[r-1] - arr[l-1] << endl;
    }
}

