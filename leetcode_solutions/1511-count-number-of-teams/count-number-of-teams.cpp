class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
       
        int ans=0;
        for(int j=1;j<n-1;j++)
        {
             int ll=0,lg=0,rl=0,rg=0;
            //left portion
            for(int i=0;i<j;i++)
            {
                if(rating[i]<rating[j])
                ll++;
                else if(rating[i]>rating[j])
                lg++;
            }
            //right portion
            for(int k=j+1;k<n;k++)
            {
                 if(rating[k]<rating[j])
                rl++;
                else if(rating[k]>rating[j])
                rg++;
            }
             ans+=ll*rg;
             ans+=lg*rl;
        }
       
        return ans;
    }
};