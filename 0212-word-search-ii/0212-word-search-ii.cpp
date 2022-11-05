class TrieNode{
public:
    string word;
    vector<TrieNode*>children;
    TrieNode(){
        children=vector<TrieNode*>(26,NULL);
        word="";
    }
};
class Trie{
public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void addWord(string word){
        TrieNode* curr=root;
        for(int i=0;i<word.size();i++){
            if(curr->children[word[i]-'a'] == NULL)
                curr->children[word[i]-'a']=new TrieNode();
            curr=curr->children[word[i]-'a'];
        }
        curr->word=word;
    }
};
class Solution {
private:
    Trie* trie;
    vector<vector<char>> board;
    vector<string>ans;
    int m,n;
    void dfs(int i,int j,TrieNode* root){
        if(i<0 || i==m || j<0 || j==n || board[i][j]== '#' || root->children[board[i][j]-'a'] == NULL)
            return;
        char c=board[i][j];
        root = root->children[c-'a'];
        if(root->word!=""){
            ans.push_back(root->word);
            root->word="";
        }
        board[i][j]='#';
        int di[]={1,-1,0,0};
        int dj[]={0,0,1,-1};
        for(int m=0;m<4;m++){
            dfs(i+di[m],j+dj[m],root);
        }
        board[i][j]=c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie= new Trie();
        this->board=board;
        for(string w:words)
            trie->addWord(w);
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i,j,trie->root);
            }
        }
        return ans;
    }
};