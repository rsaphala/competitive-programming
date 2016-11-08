#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#define endl '\n'
typedef long long ll;

using namespace std;

int m,n;
ll arr[100001+4];
ll dp[100001+4];

ll solve(ll num){
    if (num >= 100001) return 0;
    if (dp[num] != -1) return dp[num];
    ll a = solve(num+1);
    ll b = solve(num+2) + (arr[num] * num);
    dp[num] = max(a,b);
    return dp[num];
}

int main(){
    ios_base::sync_with_stdio(0);
    memset(arr,0,sizeof(arr));
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for (int i = 0;i<n;i++){
        cin >> m;
        arr[m]++;
    }

    cout << solve(1) <<endl;
}