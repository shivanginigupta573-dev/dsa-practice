#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{
   int i,a,b,c,ans=0;
   for(i=1;i<=n;i++)
   {
     cin>>a>>b>>c;
     if((a==1&&b==1) || (b==1 &&c==1) ||(a==1&&c==1) || (a==1 &&b==1 && c==1 ))
     ans++;
   }
   cout<<ans<<endl;
}
int main()
{
    int n;
    printf("Enter the number of integers\n");
    cin>>n;
    solve (n);
 return 0;
}