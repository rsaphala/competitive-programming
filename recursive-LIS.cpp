#include <bits/stdc++.h>


using namespace std;

vector<int>v;
map < pair<int,int>, int > mp;
int n,temp;

int LIS(int num,int idx){
    if (idx == v.size()) return 0;
    pair<int,int>pr = make_pair(num,idx);
    if (mp.count(pr)){
        cout << pr.first << ' ' << pr.second << endl;
        return mp.at(pr);
    }
    int left,right;

    if (v[idx] > num ) left = LIS(v[idx],idx+1)+1;
    right = LIS(num,idx+1);
    if (v[idx] > num) mp.insert(make_pair(pr,max(left,right)));
    else mp.insert(make_pair(pr,right));

    return mp.at(pr);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        scanf("%d",&temp);
        v.push_back(temp);
    }
    
    printf("%d\n",LIS(-99999,0));
    return 0;
}
