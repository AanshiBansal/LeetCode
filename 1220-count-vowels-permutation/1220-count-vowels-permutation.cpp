class Solution {
public:
    int MOD=1e9+7;
    vector<vector<int>> Multiply(vector<vector<int>> &l,vector<vector<int>> &r) //Multiply two matrices applying MOD.
    {
        vector<vector<int>> result(l.size(),vector<int>(r[0].size(),0));
        for(int i=0;i<l.size();i++)
            for(int j=0;j<r[0].size();j++)
                for(int k=0;k<l[0].size();k++)
                    result[i][j]+=(long long)l[i][k]*r[k][j]%MOD,result[i][j]%=MOD;
        return result;
    }
    int countVowelPermutation(int n) 
    {
        vector<vector<int>> M={ {0,1,0,0,0},      //Adjacency matrix of graph of the problem.
                                {1,0,1,0,0},
                                {1,1,0,1,1},
                                {0,0,1,0,1},
                                {1,0,0,0,0}},result(5,vector<int>(5));
        for(int i=0;i<5;i++)   //Create identity Matrix.
            result[i][i]=1;
        int sum=0;
        n--;
        while(n)    //log(n) Multiplication.
        {
            if(n&1)
                result=Multiply(M,result);
            n>>=1;
            M=Multiply(M,M);
        }
        for(vector<int> &i:result)          //Result holds M^(N-1).
            for(int &j:i)
                sum+=j,sum%=MOD;
        return sum;
    }
};