#include<bits/stdc++.h>
using namespace std;
void solve(int n,vector<int>&a)
{
     long long sum=0;
     long long minm=2e18;
     for(int i=0;i<n;i++)
     {
        sum+=a[i];
        long long current_avg=sum/(i+1);
        if(current_avg<minm)
        {
            minm=current_avg;
            
        }
        cout<<minm<<" ";
     }
     cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        solve(n,a);
    }
}