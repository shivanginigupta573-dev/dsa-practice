class Solution {
public:
     void solver(int i,int n,int k ,vector<vector<int>>& ans,vector<int>&combo)
     {
        if (combo.size()==k)
        {
            ans.push_back(combo);
            return;
        }
        if(i==n+1)
        {
            return;
        }
        //we can take or skip the element 
        if(combo.size()<k)
        {  combo.push_back(i);
            solver(i+1,n,k,ans,combo);
            //clear for not take
            combo.pop_back();
            //dont take
            solver(i+1,n,k,ans,combo);
        }
        
    
     }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>combo;
        solver(1,n,k,ans,combo);
        return ans;
        
    }
};