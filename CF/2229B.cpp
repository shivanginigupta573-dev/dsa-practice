#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int n, vector<ll>& a, vector<ll>& b)
{
  ll sum=0;
  int idx=0;

  ll sum_maxes = 0;
  for(int i=0; i<n; i++) {
      sum_maxes+=max(a[i], b[i]);
  }

  ll max_score=LLONG_MIN;
  ll global_max=LLONG_MIN;

  
  for(int i=0;i<n; i++) 
  {   
      ll curr_pair_max=max(a[i],b[i]);
      ll curr_pair_min=min(a[i],b[i]);
      
     
      ll current_score=curr_pair_max+(sum_maxes-curr_pair_max+curr_pair_min);
      
      if(current_score>max_score) 
      {
          max_score=current_score;
          idx= i;
          global_max=curr_pair_max; 
      }
  }


  b[idx]=min(a[idx],b[idx]);
  for(int i=0;i<n;i++)
  {  
     if(i != idx)
        b[i]=max(a[i],b[i]);
  }

  for(int i=0;i<n;i++)
  {
     sum=sum+b[i];
  }
  
  cout << global_max+sum<< endl;
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
        vector<ll>b(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        solve(n,a,b);
    }
}