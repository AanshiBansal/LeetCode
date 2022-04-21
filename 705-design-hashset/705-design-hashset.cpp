class MyHashSet {
private:
    vector<bool>hs;
public:
    MyHashSet() {
        hs=vector<bool>(1000001,false);
    }
    
    void add(int key) {
        hs[key]=true;
    }
    
    void remove(int key) {
        hs[key]=false;
    }
    
    bool contains(int key) {
        return hs[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */