class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& oi, int fs, int fe) {
        sort(oi.begin(),oi.end());
        vector<int>interval=oi[0];
        vector<vector<int>>ans;
        for(int i=1;i<oi.size();i++)
        {
            if(oi[i][0]<=interval[1]+1)
            {
                interval[0]=min(interval[0],oi[i][0]);
                interval[1]=max(interval[1],oi[i][1]);
            }
            else
            {
                ans.push_back(interval);
                interval=oi[i];
            }
        
        }
        ans.push_back(interval);
        vector<vector<int>> res;

for (auto &it :ans)
{
    int l = it[0];
    int r = it[1];

    // No overlap
    if (r < fs || l > fe)
    {
        res.push_back(it);
        continue;
    }

    // Left part remains
    if (l < fs)
        res.push_back({l, fs - 1});

    // Right part remains
    if (r > fe)
        res.push_back({fe + 1, r});
    }

    
    return res;
}
};