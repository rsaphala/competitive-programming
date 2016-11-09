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

using namespace std;

int n,m;
int dp[151][151];

int solve(int a,int b){
    if (a <= 0 || b <= 0){
        if (!a && b > 0 )return 0;
        if (!b && a > 0) return 0;
        return -1;
    }
    if (dp[a][b] != -1) return dp[a][b];
    dp[a][b] = max(solve(a+1,b-2)+1,solve(a-2,b+1)+1);
    return dp[a][b];
}

int main(){
    fastIO;
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    cout << solve(n,m) << endl;
}