#include<bits/stdc++.h>
using namespace std;
void solve(int n,int k,vector<int>a)
{
    int threshold=a[k-1];
    int ans=0;
    for(int num:a)
    {
        if(num>=threshold)
        ans++;
    }
   cout<<ans<<endl;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    solve(n,k,a);
}