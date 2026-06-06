class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //asked in google //microsoft fab 
        //greedy approach
        int n=gas.size();
        int tot=0;
        int tot_cost=0;
        int curr=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            tot+=gas[i];
            tot_cost+=cost[i];
            curr+=(gas[i]-cost[i]);
            if(curr<0){
                ans=i+1;
                curr=0;
            }
        }
        if(tot_cost>tot)
         return -1;
        else
          return ans;
        
    }
};