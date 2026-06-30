#include<bits/stdc++.h>
using namespace std;
void solve(int n,int k,vector<int>& a)
{
   
    sort(a.begin(),a.end());
    if (k==0) {
        if(a[0]>1) {
            cout<<1<<endl;
        } else {
            cout<<-1<<endl;
        }
        return;
    }
    
    int x=a[k-1]; 
    if (k<n && a[k]==x) 
    {
        cout <<-1<< endl;
    } else 
    {
        cout<<x<<endl;
    }
}
int main()
{
     int n,k;
     cin>>n>>k;
     vector<int>a(n);
     for(int i=0;i<n;i++)
     {
        cin>>a[i];
     }
     solve(n,k,a);
}