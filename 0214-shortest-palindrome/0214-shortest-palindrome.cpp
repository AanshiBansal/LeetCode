// Rabin Karp Algorithm
#define d 256
#define q 1000000007
class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        if(n<=1)
            return s;
        int longest=1;
        long long firstr=s[0]%q;
        long long second=s[1]%q;
        long long factor=1;
        int length=2;
        while(length<=n){
            //cout<<length<<" "<<firstr<<" "<<second<<endl;
            if(firstr==second){
                int i=0;
                int j=length-1;
                while(i<j && s[i]==s[j]){
                    i++;
                    j--;
                }
                if(i>=j)
                    longest=length;
            }
            // preparing for next length
            if(length<n){
                if(length%2==0){
                    second=(d*(second+q-(s[length/2]*factor)%q))%q;
                    second=(second+s[length])%q;
                }else{
                    factor=(factor*d)%q;
                    firstr = (firstr + factor*s[length/2])%q;
                    second = (second*d + s[length])%q;
                }
            }
            length++;
        }
        string extra = s.substr(longest);
        reverse(extra.begin(),extra.end());
        return extra+s;
    }
};