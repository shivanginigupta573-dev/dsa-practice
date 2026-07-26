class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //search space of k
        int beg=1,end=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(beg<=end)
        {
            int mid=beg+(end-beg)/2;
           long long hrs=helper(piles,mid);
            if(hrs<=h)
            {
                ans=min(ans,mid);
                end=mid-1;
            }
            else if(hrs>h)
            {
                beg=mid+1;
            }
           
        }
        
    return ans;
        
    }
    long long helper(vector<int>&piles,int k)
    {
        long long  hours=0;
        for(int p:piles)
        {
            hours+=ceil((double)p/k);
        }
        return hours;
    }
};