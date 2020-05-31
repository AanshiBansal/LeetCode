class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int> >sol;
        int m=A.size();
        int n=B.size();
        int i=0;
        int j=0;
        while(i<m && j<n){
            int l=max(A[i][0],B[j][0]);
            int r=min(A[i][1],B[j][1]);
            if(l<=r){
                vector<int>ans(2);
                ans[0]=l;
                ans[1]=r;
                sol.push_back(ans);
            }
            if(A[i][1]<B[j][1])
                i++;
            else{
                if(A[i][1]==B[j][1])
                {i++;j++;}
                else
                    j++;
            }
        }
        return sol;
    }
};
