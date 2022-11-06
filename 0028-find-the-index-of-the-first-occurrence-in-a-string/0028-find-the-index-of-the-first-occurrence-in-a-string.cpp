#define base 256
#define mod 1000000007
class Solution {
private:
    bool compare(string &haystack, string &needle, int start){
        int i=0;
        while(i<needle.size() && needle[i]==haystack[i+start]){
            i++;
        }
        return i==needle.size();
    }
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size())
            return -1;
        long long hashNeedle=0;
        long long hashHay=0;
        long long factor=1;
        for(int i=0;i<needle.size();i++){
            hashNeedle = ((hashNeedle*base)%mod + needle[i])%mod;
            hashHay = ((hashHay*base)%mod + haystack[i])%mod;
            if(i!=0)
                factor=(factor*base)%mod;
        }
        if(hashHay == hashNeedle && compare(haystack,needle,0)){
            return 0;
        }
        for(int i=0;i+needle.size()<haystack.size();i++){
            hashHay = (((hashHay + mod - (haystack[i]*factor)%mod)*base)%mod + haystack[needle.size()+i])%mod;
            if(hashHay == hashNeedle && compare(haystack,needle,i+1)){
                return i+1;
            }
        }
        return -1;  
    }
};