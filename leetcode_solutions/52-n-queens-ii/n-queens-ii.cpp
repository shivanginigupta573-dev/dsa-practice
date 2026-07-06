class Solution {
public:
    int total=0;
    void dfs(int row,int n,int cols,int d1,int d2)
    {
        if(row==n)
        {
            total++;
            return;
        }
        int available=((1<<n)-1)& ~(cols|d1|d2);
        while(available)
        {
            int pos=available &(-available);
            available &=available-1;
            dfs(row+1,n,cols|pos,(d1|pos)<<1,(d2|pos)>>1);
        }
    }
    int totalNQueens(int n) {
        dfs(0,n,0,0,0);
        return total;
        
    }
};