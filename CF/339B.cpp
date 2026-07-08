#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    vector<ll>a(m);
    for(ll i=0;i<m;i++)
    {
        cin>>a[i];
    }
    ll x=1;
    ll ans=0;
    for(ll i=0;i<m;i++) { 
        if(x<=a[i]){ 
            ans+=(a[i]-x); 
            x=a[i];
        } 
        else{
            ans += (n-x) + a[i];
            x = a[i]; 
    } 
}
    cout<<ans<<endl;

} 