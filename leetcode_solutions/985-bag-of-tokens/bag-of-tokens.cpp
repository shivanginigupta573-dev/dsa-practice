class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        sort(tokens.begin(),tokens.end());
        int l=0,ans=0;
        int r=tokens.size()-1;
        while(l<=r)
        {
            if(power>=tokens[l])
            {
                score++;
                power-=tokens[l];
                l++;
                ans=max(ans,score);
            }
            else if(score>=1)
            {
                power+=tokens[r];
                score--;
                r--;

            }
            else
            {
                break;
            }
        }
       return ans;
    }
};