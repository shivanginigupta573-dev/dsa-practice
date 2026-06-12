class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        for(char c : s1) mp[c]++;

        int n=s1.size(), m=s2.size();
        if(n>m) 
        return false;

        int match=0;
        for(int i=0;i<m;i++) {
            if(--mp[s2[i]]>=0) 
            match++;

            if(i>=n) 
            {
                if(++mp[s2[i-n]]>0) 
                match--;
            }

            if(match==n)
             return true;
        }
        return false;
    }
};