class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(int num:chalk){
            sum+=num;
        }
        k%=sum;
        int i=0;
        for(;i<chalk.size();i++){
            if(k<chalk[i])
                break;
            k-=chalk[i];
        }
        return i;
    }
};