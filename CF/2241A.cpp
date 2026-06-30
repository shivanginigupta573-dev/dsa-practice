#include<bits/stdc++.h>
using namespace std;
void solve(int x,int y)
{
    for(int i=1;i<=x;i++)
    {
        if(y*i==x)
        {
            cout<<"Yes"<<endl;
            return;
        }
        
    }
    cout<<"No"<<endl;
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        solve(x,y);
    }

return 0;
}