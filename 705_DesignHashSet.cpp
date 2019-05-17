class MyHashSet {
public:
    vector<vector<int>> HashSet;
    /** Initialize your data structure here. */
    MyHashSet() {
        HashSet=vector<vector<int>>(1000);
        HashSet.clear();
    }
    
    void add(int key) {
        size_t index=key%1000;
        auto i=HashSet[index].begin();
        while (i!=HashSet[index].end() and *i!=key) ++i;
        if (i==HashSet[index].end()) HashSet[index].push_back(key);
        
    }
    
    void remove(int key) {
        int index=key%1000;
        auto i=HashSet[index].begin();
        while (i!=HashSet[index].end() and *i!=key) ++i;
        if (i!=HashSet[index].end()) HashSet[index].erase(i);
              
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index=key%1000;
        auto i=HashSet[index].begin();
        while (i!=HashSet[index].end() and *i!=key){
            ++i;
        }
        return i!=HashSet[index].end();      
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */