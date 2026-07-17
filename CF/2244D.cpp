#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<long long>& a, int m, vector<int>& b)
{
    sort(b.begin(), b.end());
    long long ans = 0;
    int last = 0;
    for(int i = 0; i < m; i++)
    {
        long long current_block_sum = 0;
        for(int j = last; j < b[i]; j++)
        {
            current_block_sum += a[j];
        }
        ans += abs(current_block_sum);
        last = b[i];
    }
    for(int j = last; j < n; j++)
    {
        ans += a[j];
    }
    
    cout << ans << '\n';
}

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> b(m);
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        solve(n, a, m, b);
    }
    return 0;
}