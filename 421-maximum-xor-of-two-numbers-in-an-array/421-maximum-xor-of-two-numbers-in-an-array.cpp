struct TrieNode{
    vector<TrieNode*>links;
    TrieNode(){
        links=*new vector<TrieNode*>(2,NULL);
    };
};
class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root=new TrieNode();
        };
    
        void insert(int num){
            TrieNode* curr=root;
            int bit;
            for(int i=31;i>=0;i--){
                bit=(num>>i)&1;
                if(curr->links[bit]==NULL){
                    curr->links[bit]=new TrieNode();
                }
                curr=curr->links[bit];
            }
        };
        
        int findMax(int num){
            TrieNode* curr=root;
            int maxNum=0;
            int bit;
            for(int i=31;i>=0;i--){
                bit=(num>>i)&1;
                bit=1-bit;
                if(curr->links[bit]!=NULL){
                    maxNum|=(1<<i);
                    curr=curr->links[bit];
                }else{
                    curr=curr->links[1-bit];
                }
                
            }
            return maxNum;
        };
        
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int num:nums){
            trie.insert(num);
        }
        int maxi=0;
        for(int num:nums){
            maxi=max(maxi,trie.findMax(num));
        }
        return maxi;
    }
};