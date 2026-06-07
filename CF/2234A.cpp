#include<bits/stdc++.h>
using namespace std;
void solve(int n,vector<int>&b)
{
      int i;
      sort(b.begin(),b.end(),greater<int>());
      int poss=1;
    for(i=0;i<n-2;i++)
    {
        if(b[i+2]!=(b[i] % b[i + 1]))
        {
            poss=0;
            break;
        }
    }
      
      if(poss==1)
      {
         cout<<b[0]<<" "<<b[1]<<endl;
      }
      else{
        cout<<-1<<endl;
      }
      
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>b(n);
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        solve(n,b);
    }
    return 0;
}