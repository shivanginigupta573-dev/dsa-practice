#include<bits/stdc++.h>
using namespace std;
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
        bool isSorted=true;
        for(int i=1;i<n;i++)
        {
            if(a[i-1]>a[i])
            {
                isSorted=false;
                break;
            }

        }
        if(k==1 )
        {
            if(isSorted==false)
            cout<<"NO"<<endl;
            else
            cout<<"YES"<<endl;
        }
        else if(k>=2){
            cout<<"YES"<<endl;
        }
    }
}