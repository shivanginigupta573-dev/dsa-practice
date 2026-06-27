#include<bits/stdc++.h>
using namespace std;
void solve(int n,vector<int>&x,int q,vector<int>m)
{
    sort(x.begin(),x.end());
    for(int i=0;i<q;i++)
    {
        int beg=0,end=n-1;
        int ans=0;

        while(beg<=end)
        {
            int mid=beg+(end-beg)/2;

            if(x[mid]<=m[i])
            {
                ans=mid+1;  // number of shops possible till mid
                beg=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }

        cout<<ans<< "\n";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>x(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    int q;
    cin>>q;
    vector<int>m(q);
    for(int i=0;i<q;i++)
    {
          cin>>m[i];
    }
    solve(n,x,q,m);
}