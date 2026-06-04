class Solution {
public:
 // int sum=0;
    int lcs(int i,int j,string &s1 ,string & s2,vector<vector<int>>& memo)
    {
        if(i==0 || j==0)
        {
            return 0;
        }
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        if(s1[i-1]==s2[j-1])
        {
            return memo[i][j]=(int)s1[i-1]+lcs(i-1,j-1,s1,s2,memo);
        }
        else
        {
           // sum=sum+(int)s1[i-1]+(int)s2[j-1];
            return memo[i][j]=max(lcs(i-1,j,s1,s2,memo),lcs(i,j-1,s1,s2,memo));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        //similar to lcs but th catch is whenver the letter does not match calculate the sum of ascii chracter
        //let's gooo
        int n=s1.size();
        int m=s2.size();
        int totalSum = 0;
        for (char c : s1) totalSum += (int)c;
        for (char c : s2) totalSum += (int)c;
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        int x=lcs(n,m,s1,s2,memo);
        return totalSum-(2*x);
    }
};