class Solution {
public:
    int trap(vector<int>& height) {
        //there are two approaches of this problem one is prefix sum nd another is two pointer
        int n=height.size();
        vector<int>leftMax(n),rightMax(n);
        //first we create a leftMax prefix array
        leftMax[0]=height[0];
        for(int i=1;i<n;i++)
        {
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        //rightmax
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightMax[i]=max(height[i],rightMax[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(leftMax[i],rightMax[i])-height[i];
        }
        
        return ans;
    }
};