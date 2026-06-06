class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        //intervals problem so greedy
        if(points.size()==0)
        return 0;
        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        int end=points[0][1];
        int n=points.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(points[i][0]>end ){
            ans++;
            end=points[i][1];
            }
        }
        return ans+1;
    }
};