// class WordFilter {
//    private:
//    // creating Hashmap of string and integer
//     unordered_map<string, int> mp;

//    public:
//     WordFilter(vector<string>& words) {
//         int n = words.size();
// 		// Loop through entire words array that contains all the words in dictionary
//         for (int i = 0; i < n; i++) {
//             string word = words[i];
// 			// Look at each word and create its prefix.
//             for (int j = 1;j<=word.size();j++) {
//                 string prefix = word.substr(0,j);
// 				// Loop through the word in array to generate its suffix.
//                 for (int k = 0;k<word.size();k++) {
//                     string suffix = word.substr(k, word.size());
// 					// Stroting the key in hashmap that needs to be compared in the function "f".
//                     mp[prefix + "*" + suffix] = i + 1;
//                 }
//             }
//         }
//     }

//     int f(string prefix, string suffix) {
//         string s = prefix + "*" + suffix;
//         return mp[s] - 1;
//     }
// };

struct TrieNode{
    vector<TrieNode*>child;
    int index;
    TrieNode(){
        child=vector<TrieNode*>(27,NULL);
        index=-1;
    };
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root=new TrieNode();
        };
        void insert(string &s, int index){
            TrieNode* curr=root;
            for(int i=0;i<s.size();i++){
                if(curr->child[s[i]-'a'] == NULL)
                    curr->child[s[i]-'a']=new TrieNode();
                curr->child[s[i]-'a']->index=index;
                curr=curr->child[s[i]-'a'];
            }
        };
        int find(string &s){
            TrieNode* curr=root;
            for(int i=0;i<s.size();i++){
                if(curr->child[s[i]-'a']==NULL)
                    return -1;
                curr=curr->child[s[i]-'a'];
            }
            return curr->index;
        }
};

class WordFilter {
private:
    Trie* t;
public:
    WordFilter(vector<string>& words) {
        t=new Trie();
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                //string prefix=words[i].substr(0,j);
                string suffix=words[i].substr(j);
                string word=suffix+"{"+words[i];
                t->insert(word,i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string word=suffix+"{"+prefix;
        return t->find(word);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */