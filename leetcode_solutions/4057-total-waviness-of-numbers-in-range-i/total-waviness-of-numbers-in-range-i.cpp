class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int totwaviness=0;
        for(int i=num1;i<=num2;i++)
            {
                totwaviness+=countWaviness(i);
            }
        
        return totwaviness;
    }
    int countWaviness(int n)
    {
        vector<int>digits;
        int d;
        while(n>0)
            {
              d=n%10; 
              digits.push_back(d);
                n=n/10;
            }
        reverse(digits.begin(),digits.end());
        int len,ans=0;
        len=digits.size();
        for(int i=1;i<len-1;i++)
            {
                 if ((digits[i] > digits[i - 1] && digits[i] > digits[i + 1])|| 
                (digits[i] < digits[i - 1] && digits[i] < digits[i + 1])) 

                {
                    ans++;
                }
            }
        return ans;
        
    }
};