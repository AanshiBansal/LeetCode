class Solution {
private:
    bool rec(vector<int>& matchsticks, int index, vector<int>&sides, int length){
        if(index==matchsticks.size()){
            for(int i=1;i<4;i++){
                if(sides[i]!=sides[i-1])
                    return false;
            }
            return true;
        }
        for(int i=0;i<4;i++){
            sides[i]+=matchsticks[index];
            if(sides[i]<=length && rec(matchsticks,index+1,sides,length))
                return true;
            sides[i]-=matchsticks[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        vector<int>sides(4,0);
        int sum=0;
        for(int s:matchsticks)
            sum+=s;
        if(sum%4 !=0)
            return false;
        sort(matchsticks.begin(),matchsticks.end(),greater());
        return rec(matchsticks,0,sides,sum/4);
    }
};