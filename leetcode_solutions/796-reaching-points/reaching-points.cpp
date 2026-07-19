class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>=sx && ty>=sy)
        {
            if(tx>ty)
            {
                if(sy==ty)
                {
                    //we only need to matcj tx
                    return (tx-sx)%ty==0;
                }
                tx=tx%ty;
            }
            else
            {
                if(tx==sx)//we only need to match ty
                {
                    return (ty-sy)%tx==0;
                }
                ty=ty%tx;
            }
        }
        return false;
    }
};