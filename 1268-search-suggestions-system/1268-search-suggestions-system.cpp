class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
        for(int i=0;i<searchWord.size();i++){
            string curr=searchWord.substr(0,i+1);
            int index=lower_bound(products.begin(),products.end(),curr)-products.begin();
            int count=3;
            vector<string>r;
            while(index<products.size()&&count--){
                if(products[index].substr(0,i+1)==curr){
                    r.push_back(products[index]);
                    index++;
                }else
                    break;
            }
            ans.push_back(r);
        }
        return ans;
    }
};