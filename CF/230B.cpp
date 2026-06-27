#include<bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false; 
        }
    }
    
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<long long >a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        long long r = sqrt(a[i]);
        if(r*r!=(double)a[i])
        cout<<"NO"<<endl;
        else
        {
            if(isPrime(r))
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
    }
    return 0;
}