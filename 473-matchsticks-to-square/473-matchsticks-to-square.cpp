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
            // pruning 4
            // if same length of sides then we can skip
            if(i>0 && sides[i]==sides[i-1])
                continue;
            sides[i]+=matchsticks[index];
            // pruning 5
            // if side's length exceeds length of square, no need to proceed further
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
        // pruning 1
        if(sum%4 !=0)
            return false;
        // pruning 2
        for(int s:matchsticks)
            if(s>sum/4)
                return false;
        // pruning 3
        // put longer matchsticks first - shortens tree
        sort(matchsticks.begin(),matchsticks.end(),greater());
        return rec(matchsticks,0,sides,sum/4);
    }
};