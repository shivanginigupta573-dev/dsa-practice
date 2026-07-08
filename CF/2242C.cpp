#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    
    vector<int>v;
    int x, last=-1,cnt=0;
    for (int i=0;i<n;i++) {
        cin>>x;
        if(i>0 && x!=last) {
            v.push_back(cnt);
            cnt=0;
        }
        cnt++;
        last=x;
    }
    v.push_back(cnt);
    sort(v.begin(),v.end());

    long long S=0;
    for (int freq:v) 
    S+=freq;
    
    int rem=v.size(),ans = 0;
    for (int i=0;i<v.size();i++) {
        if (i==0 ||v[i]!= v[i-1]) {
            if ((k-S) % rem == 0 && (S - k) / rem < v[i]) {
                ans++;
            }
        }
        S-=v[i];
        rem--;
    }
    cout<<ans<<"\n";
}

int main() {
    int t; 
    cin>>t;
    while (t--) 
    solve();
    return 0;
}