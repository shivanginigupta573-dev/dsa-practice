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
    sort(a.begin(),a.end());
    int i=0,j=a.size()-1;
    int sum1=0;
    int sum2=0;
    int count=0;
     while(i<=j) {
        sum2+= a[j];
        j--;
        count++;

        sum1=0; 
        for(int x=i;x<=j;x++) {
            sum1+=a[x];
        }

        if(sum2>sum1) break;
    }
  cout<<count<<endl;
}
