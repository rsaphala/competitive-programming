#include<bits/stdc++.h>

using namespace std;

queue<int>temp;
deque<int>maxNum;
vector<int> numbers;

void push(int idx) {
    temp.push(idx);
    while(!maxNum.empty() && numbers[idx] > numbers[maxNum.back()]) maxNum.pop_back();
    maxNum.push_back(idx);
}

int getMax() {
    return numbers[maxNum.front()];
}

void pop() {
    if (temp.front() == maxNum.front()) maxNum.pop_front();
    temp.pop();
}

 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     numbers = nums;
     vector <int> results;

     for (int i = 0; i < k; i++) {
         push(i);
     }
     results.push_back(getMax());     

     for (int i = k; i < nums.size(); i++) {
         pop();
         push(i);
         results.push_back(getMax());     
     }
    
     return results;
 }

 int main() {
     vector <int> tes = {1,3,-1,-3,5,3,6,7};
     vector<int> hasil = maxSlidingWindow(tes, 3);
     for (int i = 0; i < hasil.size();i++) {
         cout << hasil[i] << endl;
     }
 }