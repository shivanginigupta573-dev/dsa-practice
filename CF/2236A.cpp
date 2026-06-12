#include<bits/stdc++.h>
using namespace std;
void solve(int n,vector<int>& h)
{
    int maxm=*max_element(h.begin(),h.end());
   int minm=*min_element(h.begin(),h.end());
   cout<<maxm-minm+1<<endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>h(n);
        for(int i=0;i<n;i++)
        {
            cin>>h[i];
        }
        solve(n,h);
    }

}
