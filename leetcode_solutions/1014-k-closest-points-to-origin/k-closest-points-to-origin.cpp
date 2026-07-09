class Solution {
public:
    double distance(int x,int y)
    {
        return sqrt(x*x + y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<double,int>>maxHeap;
        vector<pair<int,double>>dist;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            double d=distance(x,y);
            dist.push_back({i,d});

        }
        for(auto &[idx,dis]:dist)
        {
            maxHeap.push({dis,idx});
            if(maxHeap.size()>k)
            {
                maxHeap.pop();
            }
        }
        vector<vector<int>>ans;
        while(maxHeap.size()!=0)
        {
            ans.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return ans;
    }
};