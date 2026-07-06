class Solution {
public:
  int countone(int x)
  {
    int c=0;
    while(x)
    {
        x&=x-1;//kills the rightmost one
        c++;
    }
    return c;
  }
  vector<int> countBits(int n) {
        
      vector<int>ans;
      for(int i=0;i<=n;i++)
      {
        int a=countone(i);
        ans.push_back(a);
      }
      return ans;
    }
};