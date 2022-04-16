class FileSystem {
private:
    string extractLast(string s){
        int i=s.size()-1;
        while(i>=0 && s[i]!='/'){
            i--;
        };
        return s.substr(i+1);
    }
    int extractLastIndex(string s){
        int i=s.size()-1;
        while(i>=0 && s[i]!='/'){
            i--;
        };
        return i+1;
    }
    unordered_map<string,string>files;
    unordered_map<string,set<string>>folders;
public:
    FileSystem() {
        files=unordered_map<string,string>();
        folders=unordered_map<string,set<string>>();
        folders[""]=set<string>();
    }
    
    vector<string> ls(string path) {
        //cout<<"ls "<<path<<endl;
        if(path=="/")
            return ls("");
        if(folders.find(path)==folders.end())
            return {};
        return vector<string>(folders[path].begin(),folders[path].end());
    }
    
    void mkdir(string path) {
        //cout<<"mkdir "<<path<<endl;
        int index=extractLastIndex(path);
        //cout<<index<<endl;
        string prev=path.substr(0,index-1);
        //cout<<prev<<endl;
        if(folders.find(prev)!=folders.end()){
            folders[prev].insert(path.substr(index));
        }else{
            mkdir(prev);
            folders[prev].insert(path.substr(index));
        }
        folders[path]=set<string>();
        // for(auto i:folders){
        //     cout<<i.first<<" "<<i.second.size()<<endl;
        // }
    }
    
    void addContentToFile(string filePath, string content) {
        //cout<<"adcontent "<<filePath<<endl;
        if(folders.find(filePath)==folders.end()){
            mkdir(filePath);
            folders[filePath].insert(extractLast(filePath));
        }
        files[filePath]+=content;
    }
    
    string readContentFromFile(string filePath) {
        //cout<<"READ "<<filePath<<endl;
        return files[filePath];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */