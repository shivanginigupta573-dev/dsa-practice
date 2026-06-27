class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int>pairs;
        int c;
        for(int i=0;i<n;i++)
        {   c=0;
            int beg=0,end=m-1;
            int mid;
            int valid_idx=m;
            while(beg<=end)
            {
                int mid=beg+(end-beg)/2;
                long long x=(long long)spells[i]*potions[mid];
                      if(x >= success) {
                        valid_idx=mid;  
                        end=mid-1;  
                    } else {
                        beg=mid+1;
                    }
                
            }
            pairs.push_back(m-valid_idx);
        }
        return pairs;
    }
};