#include <bits/stdc++.h>
#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0);

using namespace std;

int p,f;
int dp[110][14000];
struct data{
    int price;
    int favour;
}dat[101];

int solve(int m,int idx){
    if (m > p && p < 1800) return -10000;
    if (m > p + 200) return -10000;

    if (idx == f) {
        if (m > p && m <= 2000) return -10000;
        return 0;
    }
    if (dp[idx][m] != -1) return dp[idx][m];
    int l = solve(m + dat[idx].price,idx+1) + dat[idx].favour;
    int r = solve(m,idx+1);
    return dp[idx][m] = max(l,r);
}

int main(){
    fastIO;
    while (cin >> p >> f){
        memset(dp,-1,sizeof(dp));
        for (int i = 0;i<f;i++){
            cin >> dat[i].price >> dat[i].favour; 
        }
        cout << solve(0,0) << endl;
    }
}