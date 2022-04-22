class FileSystem {
private:
    unordered_map<string,int>mp;
    string parent(string path){
        while(path[path.size()-1]!='/')
            path.pop_back();
        path.pop_back();
        return path;
    }
public:
    FileSystem() {
        mp=unordered_map<string,int>();
        mp[""]=-1;
    }
    
    bool createPath(string path, int value) {
        if(mp.find(path)!=mp.end())
            return false;
        if(mp.find(parent(path))==mp.end())
            return false;
        mp[path]=value;
        return true;
    }
    
    int get(string path) {
        if(mp.find(path)==mp.end())
            return -1;
        return mp[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */