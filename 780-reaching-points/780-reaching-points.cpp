class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx>tx || sy>ty)
            return false;
        while(tx>sx && ty>sy){
            if(tx>ty){
                tx%=ty;
            }else{
                ty%=tx;
            }
        }
        if(sx == tx && (ty-sy)%sx==0)
            return true;
        if(sy == ty && (tx-sx)%sy==0)
            return true;
        return false;
    }
};