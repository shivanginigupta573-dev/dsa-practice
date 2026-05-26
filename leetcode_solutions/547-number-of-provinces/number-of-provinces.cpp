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