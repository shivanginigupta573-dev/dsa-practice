#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    unordered_map<string,int>mp;
    while(n--)
    {
        string s;
        cin>>s;
        mp[s]++;
        if(mp[s]==1)
        {
            cout<<"OK"<<endl;
        }
        else{
            cout<<s+to_string(mp[s]-1)<<endl;
        }
    }
    return 0;
}