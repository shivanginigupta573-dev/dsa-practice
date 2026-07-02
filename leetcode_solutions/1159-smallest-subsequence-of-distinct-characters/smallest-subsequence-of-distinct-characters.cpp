class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>freq;
        unordered_map<char,bool>seen;
        stack<char>st;
        for(char c:s)
        {
            freq[c]++;
        }
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]--;
            char curr=s[i];
            if(seen[curr])
            continue;
            while(!st.empty() && st.top()>curr && freq[st.top()]>0)
            {
                seen[st.top()]=false;
                st.pop();
            }
            st.push(curr);
            seen[curr]=true;

        }
        string ans="";
        while(!st.empty())
        {
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};