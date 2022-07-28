struct Entry 
{
    int value;
    int key;
    Entry* left;
    Entry* right;
};
// Above will be my node structure for doublylink list

class LRUCache {
    
    int LRU_SIZE;
    unordered_map<int,Entry*> hashmap;
    Entry* start,*end;
    
public:
    LRUCache(int capacity) 
    {
        LRU_SIZE = capacity;   
        start = nullptr;
        end = nullptr;
    }
    
    int get(int key) 
    {
        if(hashmap.find(key) != hashmap.end())
        {
            Entry* entry = hashmap[key];
            removenode(entry);
            addToTop(entry);
            return entry->value;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(hashmap.find(key) == hashmap.end())
        {
            Entry* newentry = new Entry();
            newentry->value = value;
            newentry->key = key;
            newentry->left = nullptr;
            newentry->right = nullptr;
            if(hashmap.size() >= LRU_SIZE)
            {
                hashmap.erase(end->key);
                removenode(end);
                addToTop(newentry);
            }
            else
            {
                addToTop(newentry);
            }
            
            hashmap.insert({key,newentry});
        }
        else
        {
            Entry* entry = hashmap[key];
            entry->value = value;
            removenode(entry);
            addToTop(entry);
        }
        
    }
    
    void addToTop(Entry* entry)
    {
        entry->right = start;
        entry->left = nullptr;
        if(start)
            start->left = entry;
        start = entry;
        
        if(end == nullptr)
            end = start;
            
    }
    
    void removenode(Entry* entry)
    {
        if(entry->left)
            entry->left->right = entry->right;
        else
            start = entry->right;
        
        if(entry->right)
            entry->right->left = entry->left;
        else
            end = entry->left;
    }
    
    
    
};

/**
 * This LRUCache object can be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
