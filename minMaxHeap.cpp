#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

#define endl '\n'
using namespace std;

priority_queue<int>maxQ;
priority_queue<int, vector<int>, greater<int> > minQ;

double solve(int n){
    if (maxQ.empty()) maxQ.push(n);
    else if (minQ.empty()) minQ.push(n);
    else {
        if (maxQ.size() == minQ.size()){
            maxQ.push(n);
        } else if (maxQ.size() > minQ.size()){
            minQ.push(n);
        } else maxQ.push(n);
    }

    if (maxQ.size() == 1 && minQ.empty()) return maxQ.top();

    if (maxQ.top() > minQ.top()){
        int tempMax = maxQ.top();
        int tempMin = minQ.top();
        maxQ.pop();minQ.pop();
        maxQ.push(tempMin);minQ.push(tempMax);
    }

    int sz = maxQ.size() + minQ.size();
    if (sz % 2){
        if (maxQ.size() > minQ.size()) return maxQ.top();
        else return minQ.top();
    } else {
        double a = maxQ.top();
        double b = minQ.top();
        return (a+b)/2;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
       cout << fixed << setprecision(1) << solve(a[a_i]) << endl;
    }
    return 0;
}
