class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i,len;
        len=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int>interval=intervals[0];
        for(i=1;i<len;i++)
        {
           if(intervals[i][0]<=interval[1])
           {
            interval[0]=min(interval[0],intervals[i][0]);
             interval[1]=max(interval[1],intervals[i][1]);
           }
           else{
            ans.push_back(interval);
            interval=intervals[i];
           }
        }
        ans.push_back(interval);
        return ans;
        
    }
};