#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
 
void solve(){
 
    ll n;
    cin>>n;
 
    vector<ll>arr(n);
 
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
 
    ll k=0;
 
    for(ll i=0;i<n-1;i++){
 
        if(arr[i]>arr[i+1]){
            k=max(k,arr[i]-arr[i+1]);
        }
 
    }
 
    if(k==0){
        cout<<"YES"<<endl;
        return;
    }
 
    bool poss=true;
 
    ll last=0;
 
    for(ll i=0;i<n;i++){
 
        bool same=(arr[i]>=last);
        bool add=(arr[i]+k>=last);
 
        if(!same && !add){
 
            poss=false;
            break;
 
        }else if(same && add){
 
            last=arr[i];
 
        }else if(add){
 
            last=arr[i]+k;
 
        }else{
 
            last=arr[i];
 
        }
    }
 
    if(poss){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
 
int main(){
 
    int t;
    cin>>t;
 
    while(t--){
        solve();
    }
}