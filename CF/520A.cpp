#include<bits/stdc++.h>
using namespace std;
void panagram(string str)
{
   for (int i=0;i<str.size();i++) {
        str[i]=tolower(str[i]);
   }
   int f=0;
   unordered_map<char,int>map;
   for(char ch='a';ch<='z';ch++)
   {
      map[ch]=0;
   }
   for(char c:str)
   {  
      if((c>='a' && c<='z'))
      map[c]++;
   }
   for(auto it:map)
   {
    if(it.second==0)
    {
        f=1;
    }
   // cout<<it.first<<"  "<<it.second<<endl;
   }
   if(f==1)
   {
    cout<<"NO"<<endl;
   }
   else
   {
    cout<<"YES"<<endl;
   }
   
}
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    panagram(str);
}
