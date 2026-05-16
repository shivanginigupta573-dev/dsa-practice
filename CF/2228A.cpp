#include<bits/stdc++.h>
using namespace std;
void solve(int n, vector<int>& w) {
    sort(w.begin(), w.end());
    int oper=0;
    int l=0;
    int r=n-1;
    
    while (l<=r && w[l]==0) {
        oper++;
        l++;
    }
    
    while (l<r) {
        if (w[l]==1 && w[r]==2) {
            oper++;
            l++; 
            r--;
        } else {
            break; 
        }
    }

    if (l<=r) { 
        int remaining_elements=r-l+1;
        oper += remaining_elements/3;
    }
    
    cout <<oper<< endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>w(n);
        for(int i=0;i<n;i++)
        {
            cin>>w[i];
        }
        solve(n,w);
    }
}