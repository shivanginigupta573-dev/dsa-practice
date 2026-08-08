#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        
        int cnta[2] = {}, cntb[2] = {};
        for(int i = 0; i < n; i++) {
            cnta[i % 2] += a[i] == '1';
            cntb[i % 2] += b[i] == '1';
        }
        
        cout << (cnta[0] == cntb[0] && cnta[1] == cntb[1] ? "YES" : "NO") << endl;
    }
}