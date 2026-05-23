#include<bits/stdc++.h>
using namespace std;
void solve(int n,vector<int>& a)
{
    int minm=INT_MAX;
    int maxm=INT_MIN;
    for(int i=0;i<n;i++)
    {
        minm=min(a[i],minm);
        maxm=max(a[i],maxm);
        
    }
    cout<<((maxm-minm+1)/2)<<endl;

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