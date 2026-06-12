#include<bits/stdc++.h>
using namespace std;
void solve(int n,int k,string s)
{
   vector<int> c_ones(k, 0);

    for (int i=0;i<n;i++) {
        if (s[i]=='1') {
            c_ones[i%k]++;
        }
    }
    bool possible=true;
    for (int i=0;i<k;i++) {
        if (c_ones[i]%2!=0) {
            possible=false;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
        int k;
        cin>>k;
        string s;
        cin>>s;
        solve(n,k,s);
    }
}