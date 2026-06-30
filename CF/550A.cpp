#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int p=s.find("AB");
    if(p!=string::npos)
    {
        int q=s.find("BA",p+2);
        if (q!=string::npos){
        cout<<"YES"<<endl;
        return 0;
        }
    }
     p=s.find("BA");
    if(p!=string::npos)
    {
        int q=s.find("AB",p+2);
        if (q!=string::npos){
        cout<<"YES"<<endl;
        return 0;
        }
    }
    cout<<"NO"<<endl;
}