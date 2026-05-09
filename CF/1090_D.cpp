#include<bits/stdc++.h>
using namespace std;


void solve(int n) {
   
    vector<long long> a(n);
    
    for (int i = 0; i < n; i++) {
        long long idx = i + 1;
        a[i]=(2*idx-1)*(2*idx+1);
    }

    for (int i=0;i<n;i++) {
        cout <<a[i]<<(i==n-1?"" : " ");
    }
    cout<<"\n";
}
int main()
{
    long t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        solve(n);
    }

}