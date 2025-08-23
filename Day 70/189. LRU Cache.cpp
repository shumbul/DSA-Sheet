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

class LRUCache {
    int cap;  
    vector<int> cache;  // stores keys in order (front = most recent, back = least recent)
    unordered_map<int, int> valueMap; // maps key -> value
public:
    // Constructor: initialize with given capacity
    LRUCache(int capacity) {
        cap = capacity;
    }
    // Get value for a key
    int get(int key) {
        // Step 1: If key not in cache, return -1
        if (valueMap.find(key) == valueMap.end())
            return -1;
        cache.erase(find(cache.begin(), cache.end(), key)); // Step 2: Key is present → make it "most recently used".  Erase it from wherever it is in the cache vector
        cache.insert(cache.begin(), key); // Step 3: Insert it at the front (mark as most recent)
        return valueMap[key]; // Step 4: Return the value
    }
    // Put a key-value pair in the cache
    void put(int key, int value) {
        // Step 1: If key already exists
        if (valueMap.find(key) != valueMap.end()) {
            cache.erase(find(cache.begin(), cache.end(), key)); // Remove it from cache list (old position)
        }
        // Step 2: If cache is full → remove least recently used (last element)
        else if ((int)cache.size() == cap) {
            int lruKey = cache.back(); // LRU is last element
            cache.pop_back();          // remove it from cache
            valueMap.erase(lruKey);    // also remove its value
        }
        cache.insert(cache.begin(), key);  // Step 3: Insert the new key at the front (most recent)
        valueMap[key] = value;  // Step 4: Update value map
    }
};
//TC O(N)
//SC O(1)
