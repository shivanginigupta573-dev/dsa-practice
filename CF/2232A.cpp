#include<bits/stdc++.h>
using namespace std;
void solve(int n,vector<long long>&a)
{
    sort(a.begin(), a.end());  
    long long x=0;
    int ops=0;
    
    for(int i=0;i<n/2;i++)
    {
        if(a[i]!= a[n-1-i])
        {
            ops++;
        }
        else
        {
            break;
        }
    }
    if(x==-1)
    {
        ops=0;
    }
    
    cout << ops << endl;
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
}