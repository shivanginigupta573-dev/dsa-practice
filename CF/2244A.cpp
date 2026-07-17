#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin>>s;

    int max_time=0;
    int current_len=0;

    for (int i = 0;i<= n;++i) {
        
        if (i < n && s[i] == '#') {
            current_len++;
        } else {
            if (current_len>0) {
               
                int time=(current_len+1)/2;
                max_time=max(max_time,time);
            }
            current_len= 0;
        }
    }

    cout<<max_time<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        solve();
    }
    return 0;
}