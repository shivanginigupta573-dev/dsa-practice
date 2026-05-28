class Solution {
public:
    int find(vector<int>&arr,int x)
    {
        if(arr[x]==-1)
        {
            return x;//x is the root
        }
        //otherwise recurse to find the root
        return find(arr,arr[x]);
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>arr(n,-1);
        int comp=n;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    int rooti=find(arr,i);
                    int rootj=find(arr,j);
                    if(rooti!=rootj)
                    {
                        arr[rootj]=rooti;
                        comp--;
                    }
                }
            }
        } 
        return n-comp;       
    }
};