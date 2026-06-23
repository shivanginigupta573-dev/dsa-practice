#include<bits/stdc++.h>
using namespace std;
void solve(string str)
{
    int len=str.size();
    if(len<=10)
    {
        cout<<str<<endl;
        return;
    }
    string ans="";
    ans=str[0]+to_string(len-2)+str[len-1];
    cout<<ans<<endl;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        solve(str);
    }
}