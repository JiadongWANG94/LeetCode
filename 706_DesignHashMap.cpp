class MyHashMap {
    vector<vector<pair<int,int>>> HashMap;
    int Buckets = 1001;
    int Pos = 1000;
    int HashKey(int key){return key%1001;}
    //int HashPos(int key){return key/1001;}
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        HashMap=vector<vector<pair<int,int>>>(1001);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        vector<pair<int,int>>::iterator i=HashMap[HashKey(key)].begin();
        while (i!=HashMap[HashKey(key)].end() && i->first!=key) i++;
        if (i==HashMap[HashKey(key)].end()) HashMap[HashKey(key)].push_back(pair<int,int>(key,value));
        else i->second=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for (vector<pair<int,int>>::iterator i=HashMap[HashKey(key)].begin();i!=HashMap[HashKey(key)].end();++i) if (i->first==key) return i->second;
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        vector<pair<int,int>>::iterator i=HashMap[HashKey(key)].begin();
        while (i!=HashMap[HashKey(key)].end() && i->first!=key) i++;
        if (i!=HashMap[HashKey(key)].end()) HashMap[HashKey(key)].erase(i);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */