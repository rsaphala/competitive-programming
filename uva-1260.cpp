#include <bits/stdc++.h>
#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0);

using namespace std;

void solve(vector<int>v){
    int sum = 0;
    for (int i = 1;i<v.size();i++){
        int cnt = 0;
        int num = v[i];
        for (int j = i-1;j>=0;j--){
            if (v[j] <= num) {
                cnt++;
            }
        }
        sum+=cnt;
    }
    cout << sum << endl;
}

int main(){
    fastIO;
    int t,c,temp;
    vector<int>v;
    cin >> t;
    while(t--){
        cin >> c;
        for (int i = 0;i<c;i++){
            cin >> temp;
            v.push_back(temp);
        }
        solve(v);
        v.clear();  
    }
}