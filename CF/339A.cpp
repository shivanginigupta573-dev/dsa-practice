#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    vector<int>  num;
    for(int i=0;i<str.size();i++)
    {
        if(isdigit(str[i]))
        {
            num.push_back(str[i]-'0');
        }
    }
    sort(num.begin(),num.end());
    string newstr="";
    for(int i=0;i<num.size();i++)
    {
       newstr += to_string(num[i]);
       if (i!= num.size()-1) 
        newstr +='+';
    }
    cout<<newstr<<endl;
  return 0;
}