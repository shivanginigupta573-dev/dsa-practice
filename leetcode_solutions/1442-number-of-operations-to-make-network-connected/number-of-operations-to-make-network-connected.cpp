class Solution {
public:
int find(vector<int> &arr,int x)
{
    if(arr[x]==-1)
    return x;
    return find(arr,arr[x]);

}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()<n-1) {
            return -1;
        }
        vector<int> arr(n,-1);
        int comp=n;    
        int red=0;
        for(int i=0;i<connections.size();i++)
        {
            int a=connections[i][0];
            int b=connections[i][1];
            int roota=find(arr,a);
            int rootb=find(arr,b);
            if(roota==rootb)
            {
                red++;
            }
            else
            {
                comp--;
                //perform union
                arr[rootb]=roota;
            }
        }
        
      return comp-1;
    }
};