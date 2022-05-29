class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>v1;
        vector<int>v2;
        int curr=0;
        for(int i=0;i<version1.size();i++){
            if(version1[i]=='.'){
                v1.push_back(curr);
                curr=0;
            }else{
                curr*=10;
                curr+=(version1[i]-'0');
            }
        }
        v1.push_back(curr);
        curr=0;
        for(int i=0;i<version2.size();i++){
            if(version2[i]=='.'){
                v2.push_back(curr);
                curr=0;
            }else{
                curr*=10;
                curr+=(version2[i]-'0');
            }
        }
        v2.push_back(curr);
        int i=0;
        while(i<v1.size() && i<v2.size()){
            if(v1[i]<v2[i])
                return -1;
            if(v1[i]>v2[i])
                return 1;
            i++;
        }
        //cout<<v1.size()<<endl;
        while(i<v1.size()){
            //cout<<i<<" "<<v1[i]<<endl;
            if(v1[i]>0)
                return 1;
            i++;
        }
        while(i<v2.size()){
            if(v2[i]>0)
                return -1;
            i++;
        }
        return 0;
    }
};