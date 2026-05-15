#include<bits/stdc++.h>
using namespace std;
//let's try brute force then try to optimise it
void solve(vector<int>&h,int n,int k)
{
     int i,j,sum=0,minsum=INT_MAX,ans=0;
    for( i=0;i<k;i++)
    {
        sum+=h[i];
    }
    minsum=sum;
    for(i=1;i<=n-k;i++)
    {
        sum=sum+h[i+k-1]-h[i-1];
        if(sum<minsum)
        {
            minsum=sum;
            ans=i;
        }
    }
     cout<<ans+1<<endl; 
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>h(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    solve(h,n,k);
}