#include<bits/stdc++.h>
using namespace std;
void solve(long long x)
{
    long long tmp=x;
    long long c=0;
    while(tmp>0)
    {
        
        c++;
        tmp/=10;
    }
   cout << (long long)round(pow(10, c)) + 1 << endl;


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x;
        cin>>x;
        solve(x);
    }
}