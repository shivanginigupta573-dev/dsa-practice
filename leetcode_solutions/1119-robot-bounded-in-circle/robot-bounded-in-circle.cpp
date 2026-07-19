class Solution {
public:
    bool isRobotBounded(string s) {
        int x=0,y=0,dir=0;
    for(char c:s) 
    {
        if(c=='G') 
        {
            if(dir==0) 
            y++;
            else if(dir==1) 
            x++;
            else if(dir==2)
            y--;
            else 
            x--;
        } 
        else if(c=='L') 
        dir=(dir+3)%4;
        else if(c=='R') 
        dir=(dir+1)%4;
    }
    return (x==0 && y==0) || dir!=0;
    }
};