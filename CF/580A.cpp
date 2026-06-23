#include<bits/stdc++.h>
using namespace std;
void solve(int n,vector<int>a)
{
    int c=0,maxm=0;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]<=a[i])
        {
            c++;
            maxm=max(c,maxm);
        }
        else{
            c=0;
        }
    }
    cout<<maxm+1<<endl;
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
    solve(n,a);
}