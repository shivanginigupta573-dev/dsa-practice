#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int>ps(n);
    ps[0]=a[0];
    for(int i=1;i<n;i++)
    {
        ps[i]=ps[i-1]+a[i];
    }
    int ans=0;
    int maxm=INT_MIN;
   int l=0;
     for(int l=0;l<n;l++)
    {
        for(int r=l;r<n;r++)
        {
           int ones;
           if(l==0)
           {
               ones=ps[r];
           }
           else
           {
               ones=ps[r]-ps[l-1];//using range query
           }
           int zeros=(r-l+1)-ones;//window size -zeroes
           ans=ps[n-1]-ones+zeros;
           maxm=max(ans,maxm);
        }
    }
   cout<<maxm<<endl;

}