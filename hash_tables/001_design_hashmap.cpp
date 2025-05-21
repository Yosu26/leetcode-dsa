#include<iostream>
#include<vector>

class MyHashmap{
    private:
    static const int SIZE = 1000;
    std::vector<std::vector<std::pair<int, int>>> buckets;

    int hash(int key){
        return key % SIZE;
    }

    public:
    MyHashmap(){
        buckets.resize(SIZE);
    }

    void put(int key, int value) {
        int idx = hash(key);
        for(auto& pair : buckets[idx]){
            if(pair.first == key){
                pair.second = value;
                return;
            }
        }
        buckets[idx].emplace_back(key, value);
    }
    
    int get(int key) {
        int idx = hash(key);
        for(const auto& pair : buckets[idx]){
            if(pair.first == key){
                return pair.second; 
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto& bucket = buckets[idx];
        for(auto it = bucket.begin(); it!=bucket.end(); ++it ){
            if(it->first == key){
                bucket.erase(it);
                return;
            }
        }
    } 
};