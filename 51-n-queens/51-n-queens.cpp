class Solution {
public:
    bool check(int r, int c, int n, vector<bool>mapcol,vector<bool>maprd,vector<bool>mapld){
        return r<n && c<n && mapcol[c]==false && maprd[r-c+n-1]==false && mapld[r+c]==false;
    }
    void queen(vector<vector<string>> &result, vector<string>ans, vector<bool>mapcol, vector<bool>maprd, vector<bool>mapld, int r,int n)
    {
        if(r==n)
        {result.push_back(ans);
         return;}
        for(int i=0;i<n;i++){
            if(check(r,i,n,mapcol,maprd,mapld))
            {
                mapcol[i]=true;
                maprd[r-i+n-1]=true;
                mapld[r+i]=true;
                ans[r][i]='Q';
                queen(result,ans,mapcol,maprd,mapld,r+1,n);
                mapcol[i]=false;
                maprd[r-i+n-1]=false;
                mapld[r+i]=false;
                ans[r][i]='.';
            }   
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        string help="";
        for(int i=0;i<n;i++)
            help+=".";
        vector<vector<string>>result;
        vector<string>ans(n,help);
        //vector<bool>maprow(n,false);
        vector<bool>mapcol(n,false);
        vector<bool>maprd(2*n-1,false);
        vector<bool>mapld(2*n-1,false);
        queen(result,ans,mapcol,maprd,mapld,0,n);
        return result;
    }
};