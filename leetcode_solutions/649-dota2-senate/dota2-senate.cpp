class Solution {
public:
    string solve(queue<int>radiant,queue<int>dire,int n)
    {
        while(!radiant.empty() && !dire.empty())
        {
            int i=radiant.front();
            radiant.pop();
            int j=dire.front();
            dire.pop();
            if(i>j)//dire will vote first
            {
                dire.push(j+n);
            }
            else
            {
                radiant.push(i+n);
            }
        }
      return radiant.empty()?"Dire":"Radiant";
    }
    string predictPartyVictory(string senate) {
        queue<int>radiant;
        queue<int>dire;
        int n=senate.size();
         for(int i=0;i<n;i++)
         {
            if(senate[i]=='R')
            radiant.push(i);
            else
            dire.push(i);
         }
         return solve(radiant,dire,n);
    }
};