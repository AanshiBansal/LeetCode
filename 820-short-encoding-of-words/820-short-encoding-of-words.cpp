bool comparator(string a, string b){
    return a.size()>b.size();
}
struct TrieNode{
    vector<TrieNode*>child;
    TrieNode(){
        child=vector<TrieNode*>(26,NULL);
    };
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root=new TrieNode();
        };
        bool insert(string s){
            TrieNode* curr=root;
            bool ans=false;
            for(int i=0;i<s.size();i++){
                if(curr->child[s[i]-'a']==NULL){
                    ans=true;
                    curr->child[s[i]-'a']=new TrieNode();
                }
                curr=curr->child[s[i]-'a'];
            }
            return ans;
        };
    
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans=0;
        int n=words.size();
        Trie* t=new Trie();
        sort(words.begin(),words.end(),comparator);
        for(int i=0;i<n;i++){
            reverse(words[i].begin(),words[i].end());
            if(t->insert(words[i]))
                ans+=words[i].size()+1;
        }
        return ans;
    }
};