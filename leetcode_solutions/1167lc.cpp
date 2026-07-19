/*
Given n ropes with lengths arr[i]. Connect all ropes into one.
Cost to connect 2 ropes = sum of their lengths.
Find minimum total cost.

Example: [2][4][3][6] ->
Connect 2+3=5 cost=5, arr=
Connect 4+5=9 cost=9+5=14, arr=
Connect 6+9=15 cost=15+14=29
Answer 29[4][5][6][9]
*/
#include<bits/stdtr1c++.h>
using namespace std;
int minCost(int n,vector<int>&arr)
{
    priority_queue<int,vector<int>,greater<int>>pq;
   for(int x:arr)
   {
    pq.push(x);
   }
   int cost=0;
   while(pq.size()>1)//stop when size <2 because second pop may crash
   {
    int a=pq.top();
    pq.pop();
    int b=pq.top();
    pq.pop();
    cost=cost+a+b;
    pq.push(a+b);
   }
   return cost;
}
int main()
{
int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<minCost(n,arr)<<endl;
}