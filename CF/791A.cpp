#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,year=0;
    cin>>a>>b;
    while(true)
    {   if(a>b)
        {
            cout<<year<<endl;
            break;
        }
        a=a*3;
        b=b*2;
        year++;

    }
    return 0;
}