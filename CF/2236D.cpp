#include<bits/stdc++.h>
using namespace std;
void solve(int n,int k,vector<int>&a)
{
   sort(a.begin(), a.end());

    // Group elements from the end going backwards
    int cnt = 1;
    bool same = true;

    for (int i = n - 1; i > 0; i--) {
        // If we hit a gap greater than k, the last component ends here
        if (a[i] - a[i - 1] > k) {
            break;
        }
        cnt++;
        if (a[i] != a[i - 1]) {
            same = false;
        }
    }

    // Egor loses only if the final playable component has an odd size 
    // AND all elements in it are completely identical
    if ((cnt % 2 != 0) && same) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        solve(n,k,a);
    }
}