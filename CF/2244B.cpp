#include<bits/stdc++.h>
using namespace std;

void solve(int n,vector<long long>&a)
{
    long long prev=0;
    for(int i=0;i<n-1;i++)
    {
        long long need=prev+1;
        if(a[i]<need)
        {
            cout<<"NO\n";
            return;
        }
        a[i+1]+=a[i]-need;
        prev=need;
    }

    if(a[n-1]>prev)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<long long>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        solve(n,a);
    }

    return 0;
}