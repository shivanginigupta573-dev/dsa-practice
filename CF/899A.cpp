#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int one=0,two=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        one++;
        else
        two++;
    }
    int ans;
    if(one >= two) {
        ans = two + (one - two)/3;
    } else {
        ans = one; // or two? depends on problem
    }
    cout<<ans<<endl;
}