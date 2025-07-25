class LRUCache {
    int cap;
    list<int> lru; // Maintains keys in order of usage: front = most recently used
    unordered_map<int, int> valueMap; // Maps key to its value
    unordered_map<int, list<int>::iterator> posMap; // Maps key to its position in the list

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) 
    {
        if (valueMap.find(key) == valueMap.end()) 
            return -1;
        // Move accessed key to the front of the list (most recently used)
        lru.erase(posMap[key]); // Remove it from current position
        lru.push_front(key); // Insert at front
        posMap[key] = lru.begin(); // Update position
        return valueMap[key]; // Return the value
    }
    void put(int key, int value) {
        if (valueMap.find(key) != valueMap.end()) {
            // Key already exists — update its position
            lru.erase(posMap[key]); // Remove from old position
        } 
        else if (lru.size() == cap) {
            // Cache is full — remove least recently used key
            int lruKey = lru.back(); // The LRU key is at the back
            lru.pop_back(); // Remove it from the list
            valueMap.erase(lruKey); // Remove from value map
            posMap.erase(lruKey); // Remove from position map
        }
        // Insert new key at the front (most recently used)
        lru.push_front(key);
        valueMap[key] = value;
        posMap[key] = lru.begin();
    }
};
