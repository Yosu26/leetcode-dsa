#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    int capacity;
    list<pair<int, int>> lru; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cache;
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        // Move accessed node to front
        lru.splice(lru.begin(), lru, cache[key]);
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update value and move to front
            cache[key]->second = value;
            lru.splice(lru.begin(), lru, cache[key]);
        } else {
            if (lru.size() == capacity) {
                // Remove least recently used
                int oldKey = lru.back().first;
                lru.pop_back();
                cache.erase(oldKey);
            }
            lru.emplace_front(key, value);
            cache[key] = lru.begin();
        }
    }
};