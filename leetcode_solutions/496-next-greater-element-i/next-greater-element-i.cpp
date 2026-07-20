class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreater;
        vector<int> ans;
        stack<int> st;
        for (int num : nums2) {
            while (!st.empty()&&num>st.top()) {
                nextGreater[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }
        
        for (int i=0;i<nums1.size();i++) {
            ans.push_back(nextGreater[nums1[i]]);
        }
     return ans;
    }

};