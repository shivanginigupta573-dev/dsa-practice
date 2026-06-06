class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //interval problem so greedy algorithm works iguess lets tryy
        if(intervals.size()==0)
        {
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int n=intervals.size();
        int ans=0;
        int last=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<last )
            {
                //remove that
                ans++;
            }
           else
           {
            last=intervals[i][1];
           }
        }
      return ans;
        
    }
};