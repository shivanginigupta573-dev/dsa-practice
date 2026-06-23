#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    unordered_set<char>set;
    for(char ch:str)
    {
        set.insert(ch);
    }
    int n=set.size();
    if(n%2==1)
    {
        cout<<"IGNORE HIM!"<<endl;
        
    }
    else
    {
        cout<<"CHAT WITH HER!"<<endl;
    }
    return 0;
}