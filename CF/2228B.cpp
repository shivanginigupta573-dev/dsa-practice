#include<bits/stdc++.h>
using namespace std;
void solve(long long n,long long x1,long long x2,long long k)
{
  if(n<=3)
  {
    cout<<1<<endl;
    return;
  }
    cout<<k+min(abs(x2-x1),n-abs(x2-x1))<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,x1,x2,k;
        cin>>n>>x1>>x2>>k;
        solve(n,x1,x2,k);
    }
}
