#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> &a, int n) {
   for (int i=0;i<n;i++) {
        a[i*3]=i+1;
    }
    int current=n+1;
    for (int i=0;i<n;i++) {
        a[i*3+1]=current++;
        a[i*3+2]=current++;
    }

    for (int i=0;i<3*n;i++) {
        cout << a[i] << (i==3*n-1? "" : " ");
    }
    cout << endl;
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(3 * n);
        solve(a, n);
    }
    return 0;
}