#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
   int n;
   cin>>n;
   int maxmA=0;
   vector<int>a(n);
   for(int i=0;i<n;i++)//similar to robbers problem of leetcode
   {
      cin>>a[i];
      maxmA=max(maxmA,a[i]);
   }
   vector<ll>cnt(maxmA+1,0);
   vector<ll>dp(maxmA+1,0);
   for(int x:a)
   {
      cnt[x]++;
   }
   dp[1]=cnt[1]*1LL;
   for(int i=2;i<=maxmA;i++)
   {
      dp[i]=max(dp[i-1],dp[i-2]+i*cnt[i]);
   }
   cout<<dp[maxmA]<<endl;

}