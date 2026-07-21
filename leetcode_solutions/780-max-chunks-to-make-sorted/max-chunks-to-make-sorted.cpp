class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n=arr.size();
        int ans=0;
        int maxm=0;
        for(int i=0;i<n;i++)
        {
            maxm=max(maxm,arr[i]);
            if(maxm==i)
            ans++;
           
        }
        return ans;
    }
};