#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{
 if (n==1)
 {
    cout<<1<<endl;
    return;
 }
 vector<int>a;
 for(int i=n-1;i<=n*2-2;i++)
 {
    a.push_back(i);
 }
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
int main()
{
    int t;
    cin>>t ;
    while(t--)
    {
        int n;
        cin>>n;
        solve(n);
    }
    return 0;
}