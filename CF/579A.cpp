#include<bits/stdc++.h>
using namespace std;
void solve(int  x)
{
    int count=0;
    while (x>0) 
    {
        x=x&(x-1); 
        count++;       
    }
    cout << count << endl;
}
int  main()
{
    int  x;
    cin>>x;
    solve(x);
    return 0;
}