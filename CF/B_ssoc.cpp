#include <bits/stdc++.h>
using namespace std;
int solve() {
     int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<bool> mkd(n + 1, false);
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (mkd[i]) break;        
        if (p[i] <= i) {         
            count++;
            mkd[p[i]] = true;   
        }
       
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        cout <<solve()<<endl;
    }
    return 0;
}