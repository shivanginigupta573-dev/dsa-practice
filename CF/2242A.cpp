#include<bits/stdc++.h>
using namespace std;
 void solve()
 {
    int k;
    cin>>k;
    vector<int>c(k);
    for(int i=0;i<k;i++)
    {
        cin>>c[i];
    }
   int ge2 = 0; // how many letters have count >= 2
    bool ge3 = false; // is there any letter with count >= 3

    for(int x : c) {
        if(x >= 3) ge3 = true; // if one char appears 3+ times, we can do aaa
        if(x >= 2) ge2++; // count chars that appear at least twice
    }

    if(ge3 || ge2 >= 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;

    }
    
 }
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}