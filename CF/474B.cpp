#include<bits/stdc++.h>
using namespace std;
void solve(int n,vector<int>& a,int m,vector<int>&q)
{
    vector<int>ps(n);
    ps[0]=a[0];
    for(int i=1;i<n;i++)
    {
        ps[i]=ps[i-1]+a[i];
    }
    vector<int>ans;
    int k=0;
    while(k!=m)
    {
        int idx=lower_bound(ps.begin(), ps.end(), q[k]) - ps.begin();
        cout<<idx+1<<'\n';
        k++;
    }

}
int main()
{
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }
   int m;
   cin>>m;
   vector<int>q(m);
   for(int i=0;i<m;i++)
   {
    cin>>q[i];
   }
   solve(n,a,m,q);
}