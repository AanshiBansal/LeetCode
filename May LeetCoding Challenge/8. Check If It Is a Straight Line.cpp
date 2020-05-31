class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coord) {
        if(coord[1][0]==coord[0][0]){
            for(int i=2;i<coord.size();i++)
                if(coord[i][0]!=coord[0][0])
                    return false;
            return true;
        }
        double slope=double(coord[1][1]-coord[0][1])/double(coord[1][0]-coord[0][0]);
        for(int i=2;i<coord.size();i++){
            double temp=double(coord[i][1]-coord[0][1])/double(coord[i][0]-coord[0][0]);
            if(temp!=slope)
                return false;
        }
        return true;
    }
};
