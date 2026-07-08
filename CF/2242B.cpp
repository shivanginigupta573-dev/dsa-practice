#include<bits/stdc++.h>
using namespace std;
void solve(int n,vector<int>&a)
{
    vector<long long>val(n); 
    vector<long long>sufMax(n);

    int c1=0,c2=0,c3=0;
    for(int i=0;i<n; i++) {
        if(a[i] == 1) 
        c1++;
        else if(a[i] == 2) 
        c2++;
        val[i] = 2LL*(c1+c2)-(i + 1);
    }
    sufMax[n-1] = LLONG_MIN;
    for(int i = n-2; i >= 0; i--) {
        sufMax[i] = max(sufMax[i+1],val[i]);
    }

    c1=0,c2 = 0,c3 = 0;
    int grp=1;

    for(int i = 0; i < n; i++) {
        if(a[i] == 1) c1++;
        else if(a[i] == 2) c2++;
        else c3++;

        if(grp == 1) {
            if(2 * c1 >= i + 1) {
                if(i + 1 <= n - 2) {
                    long long val_i = 2LL * (c1 + c2) - (i + 1);
                    if(sufMax[i + 1] >= val_i) {
                        grp = 3; 
                        break;
                    }
                }
            }
        }
    }

    if(grp == 3) 
    cout <<"YES\n";
    else cout << "NO\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        solve(n,a);
    }
}