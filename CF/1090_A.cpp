#include<bits/stdc++.h>
using namespace std;
void solve(int x)
{
    if(x==67)
    cout<<x<<endl;
    else
    cout<<(x+1)<<endl;
}
int main()
{
     int t;
     cin>>t;
     while(t--)
     {
        int x;
        cin>>x;
        solve(x);
     }
     return 0;
}