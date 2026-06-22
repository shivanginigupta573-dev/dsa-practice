class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int,char>mp;
        int k=0;
        string newstr="";
        for(int i=0;i<words.size();i++)
        {  int sum=0;
            for(char c:words[i])
            {
               sum=sum+weights[c-'a'];
            }
            sum=sum % 26;
            sum=25-sum;
            newstr=newstr+(char)(sum+'a');
            
        }
       return newstr;
        
    }
};