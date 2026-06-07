class Solution {
public:
    void solver(int i,string s,string str,vector<string>& ans,int dot)
    {
        if(dot==0){
            string rem=s.substr(i);
            if(isValid(rem))
            {
                ans.push_back(str+rem);
            }
            return;
        }
        for(int len=1;len<=3 && i+len<=s.size();len++)
        {
            string part=s.substr(i,len);
            if(isValid(part))
            {
                solver(i+len,s,str+part+".",ans,dot-1);
            }
        }
    }
       bool isValid(string segment)
       {
        if(segment.empty() || segment.size()>3)
        return false;
        if(segment.size()>1 && segment[0]=='0')
        return  false;
        long long num=stoll(segment);
        return num<=255;
       }
       
    
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        int n=s.size();
        if(n>=4 && n<=12)
        {
            solver(0,s, "",ans,3);
        }

       return ans; 
    }
};