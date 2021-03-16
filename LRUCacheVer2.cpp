class LRUCache {
private:
    list<pair<int,int>> dll;
    unordered_map<int,list<pair<int,int>>::iterator> cache;
    int LRU_SIZE;
    
public:
    LRUCache(int capacity) {
        LRU_SIZE = capacity;
    }
    
    int get(int key) 
    {
        if(cache.find(key) == cache.end())
            return -1;
        
        dll.splice(dll.begin(),dll,cache[key]);// Basically we are updating it to the front of the list.
        
        return cache[key]->second;
        
    }
    
    void put(int key, int value) 
    {
        if(get(key) != -1)
        {
            cache[key]->second = value;
            return;
        }
        if(cache.size() == LRU_SIZE)
        {
            int delkey = dll.back().first;
            dll.pop_back();
            cache.erase(delkey);
        }
        dll.emplace_front(key,value);
        cache[key]=dll.begin();
        
    }
};

/**
* Faster runtime compared to the first version
* Runtime: 60 ms, Memory Usage: 39.9 MB,
 */
