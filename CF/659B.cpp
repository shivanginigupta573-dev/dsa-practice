#include<bits/stdc++.h>
using namespace std;
struct Node{
    string name;
    int x;
    int y;
};

void solve(vector<Node>&data, int n, int m)
{
    // grouping students by region
    map<int,vector<pair<int,string>>> regions;
    
    for(int i=0;i<n;i++)
    {
        regions[data[i].x].push_back({data[i].y, data[i].name});
    }
    
    for(int i=1;i<=m;i++)
    {
        vector<pair<int,string>>&v=regions[i];
        
      // descending order
        sort(v.begin(),v.end(),[](auto& a, auto& b){//using lamda function
            return a.first > b.first;
        });
        
        int first=v[0].first;
        int second=v[1].first;
        
      //counting how many hv score==first
        int countFirst = 0;
        for(auto& p:v) if(p.first==first) 
        countFirst++;
        
        // Counting  how many have score == second 
        int countSecond = 0;
        for(auto& p:v) if(p.first == second && p.first != first) 
        countSecond++;
        
      //?case
        if(countFirst>2 ||(countFirst==1&&countSecond>1) || (countFirst==2&&false))
        {
            cout<<"?"<<endl;
        }
        else
        {
            cout<<v[0].second << " " << v[1].second << endl;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<Node> data(n);
    for(int i=0;i<n;i++)
    {
        cin>>data[i].name>>data[i].x>>data[i].y;
        
    }
    //call
    solve(data,n,m);

}