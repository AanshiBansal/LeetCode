class Solution {
private:
    unordered_map<string,int>mp1;
    unordered_map<int,string>mp2;
    int size;
public:
    Solution(){
        mp1=unordered_map<string,int>();
        mp2=unordered_map<int,string>();
        size=0;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(mp1.find(longUrl)==mp1.end()){
            mp1[longUrl]=size;
            mp2[size++]=longUrl;
        }
        return "http//tinyurl.com/"+to_string(mp1[longUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp2[stoi(shortUrl.substr(18))];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));