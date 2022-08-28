class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        if(m==0)
            return mat;
        int n=mat[0].size();
        if(n==0)
            return mat;
        for(int i=m-1;i>=-1*(n-1);i--){
            vector<int>temp;
            for(int j=0;j<m;j++){
                int k=j-i;
                if(k>=0 && k<n){
                    //cout<<i<<j<<k<<" ";
                    temp.push_back(mat[j][k]);
                }
            }
            sort(temp.begin(),temp.end());
            int x=0;
            for(int j=0;j<m;j++){
                int k=j-i;
                if(k>=0 && k<n)
                    mat[j][k]=temp[x++];
            }
        }
        return mat;
    }
};