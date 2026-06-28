class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int ans=0;
        vector<int>interval=intervals[0];
        for(int i=1;i<n;i++)
        {
           if(intervals[i][0]<interval[1])//overlaps
           {
                ans++;
                interval[0]=min(interval[0],intervals[i][0]);
                interval[1]=min(interval[1],intervals[i][1]);
           }
           else
           {
            interval=intervals[i];
           }
        } 
        return ans;
    }
};