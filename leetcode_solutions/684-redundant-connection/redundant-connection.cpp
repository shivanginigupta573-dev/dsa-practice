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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>ans;
        vector<int>arr(n+1,-1);
        int i;
        for(i=0;i<n;i++)
        {
            //first check for cycle
            int a=edges[i][0];
            int b=edges[i][1];
            int rootA = find(arr, a);
            int rootB = find(arr, b);
            if(rootA == rootB) {
                return {a, b};
            }
            arr[rootB] = rootA; 
        }
      return {};
    }
};
/*
Explantion of code
[[1,4],[3,4],[1,3],[1,2],[4,5]]
arr={-1,-1,-1,-1,-1,-1}
i=0
a=1
b=4
//find root
rootA=1,rootB=4
//no cycle so perform union
arr={-1,-1,-1,-1,1,-1,-1}
i=1
a=3 b=4
a//find root
rootA=3;
rootB=1;
//no cycle perform union
arr{-1,-1,-1,-1,3,-1,-1}


*/
