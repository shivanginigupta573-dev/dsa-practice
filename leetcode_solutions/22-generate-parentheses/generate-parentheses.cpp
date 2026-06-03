class Solution {
public:
  void solver(int x ,int y,int n,string str,vector<string>& ans)
  {
    if(x==n && y==n)
    {
        ans.push_back(str);
        return;
    }
    //open brackets
    if(x<n )
    {
        solver(x+1,y,n,str+'(',ans);
       
    }
    //close brackets
    if(y<x)
    {
        solver(x,y+1,n,str+')',ans);
    }
   
  }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solver(0,0,n,"",ans);
         return ans;
    }
};