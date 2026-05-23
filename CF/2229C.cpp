#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int n,vector<ll>& a)
{
  vector<int> b;
  bool flipped=false;
  
  for(int i=n-1;i>=0;i--)
  {
     ll current_val=a[i];
     if(flipped==true)
     {
        current_val=-a[i];
     }
     if(current_val>0)
     {
        b.push_back(i + 1); 
        flipped=!flipped; 
     }
  }
  cout <<b.size()<< endl;
  for(int i=0;i<b.size();i++)
  {
     cout <<b[i]<<(i==b.size()-1?"":" ");
  }
  cout << endl;
}
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        solve(n,a);
    }
    return 0;
}