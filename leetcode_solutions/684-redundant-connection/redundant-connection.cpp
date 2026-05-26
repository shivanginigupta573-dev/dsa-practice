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
            arr[rootA] = rootB; 
        }
      return {};
    }
};