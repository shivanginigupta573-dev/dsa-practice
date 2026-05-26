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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>arr(n,-1);
        int provinces=n;//all are their own parents
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
           if (isConnected[i][j] == 1 && i != j){
            int rooti = find(arr, i);
           int  rootj = find(arr, j);
            if (rooti!=rootj){
               // union 
               arr[rootj]=rooti;
                provinces--; }// two components merged into one
                }
            }
        }
            return provinces;
        
        
    }
};
/*
[[1,1,0],[1,1,0],[0,0,1]]
initially: provinces = 3,arr=[-1, -1, -1]
i = 0, j = 1: isConnected[0][1] == 1
  root0 = 0, root1 = 1
  Since root0 != root1:
    arr[1] = 0  = arr becomes [ -1, 0, -1 ]
    provinces- provinces becomes 2
i = 0, j = 2: isConnected[0][2] == 0 (Skip)
i = 1, j = 2: isConnected[1][2] == 0 (Skip)

Final Output: 2
*/