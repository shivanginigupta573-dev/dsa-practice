class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty() && dq.front()==i-k)
            {
                //remove cause it not in the window
                dq.pop_front();
            }
            //montonicity
            while(!dq.empty() && nums[i]>nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1)//push in ans only after we get window of size k
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};