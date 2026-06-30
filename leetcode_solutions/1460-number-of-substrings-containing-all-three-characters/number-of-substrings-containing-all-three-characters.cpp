class Solution {
public:
    int numberOfSubstrings(string s) {
        //string str="abc";
          int len=s.size();
        int ans=0;
        int cA= 0,cB = 0,cC = 0;
        int left=0;
        for (int right=0;right<len;right++) {
            if (s[right]=='a')
            cA++;
            if (s[right] == 'b')
             cB++;
            if (s[right] == 'c') 
        cC++;
            while (cA>0&&cB>0&&cC>0) {
                ans+=len-right;
                if (s[left]=='a') 
                cA--;
                if (s[left]=='b') 
                cB--;
                if (s[left]=='c')
             cC--;
                left++;
            }
        }
        return ans;
    }
};