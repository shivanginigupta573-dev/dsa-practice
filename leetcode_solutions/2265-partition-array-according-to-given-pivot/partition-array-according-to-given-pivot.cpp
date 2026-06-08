class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>less;
        vector<int> more;
        vector<int>eql;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
            less.push_back(nums[i]);
            if(nums[i]==pivot)
            eql.push_back(nums[i]);
            if(nums[i]>pivot)
            more.push_back(nums[i]);

        }
       // nums.clear();
       int k=0;
        for(int i=0;i<less.size();i++){
         nums[k++]=less[i];
        }
        for(int i=0;i<eql.size();i++){
         nums[k++]=eql[i];
        }
         for(int i=0;i<more.size();i++){
         nums[k++]=more[i];
        }

        return nums;
    }
};