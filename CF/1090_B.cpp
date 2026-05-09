#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &a)
{
     int maxm=a[0]; 
    int total_sum=0;

    for(int i=0;i<7;i++) {
        // Find the actual maximum element in the array
        if(a[i]>maxm) {
            maxm=a[i];
        }
        // Calculate the sum of all elements as they are
        total_sum+=a[i];
    }

    int result=(-total_sum)+(2*maxm);
    cout <<result<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>a(7);
        for(int i=0;i<7;i++)
        {
            cin>>a[i];
        }
        solve(a);
    }
}

