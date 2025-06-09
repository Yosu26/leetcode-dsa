#include <iostream>
#include <string>
#include <unordered_map>
#include <random>
using namespace std;

class Solution{
    private:
    unordered_map<string, string> shortToLong;
    const string base = "http://tinyurl.com/";
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    mt19937 rng{random_device{}()}; // Random number generator
    uniform_int_distribution<int> dist{0, 61}; // 62 characters in charset

    string generateKey(){
        string key;
        for(int i = 0; i < 6; ++i){
            key += charset[dist(rng)];
        }
        return key;
    }
    
    public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl){
        string key;
        do{
            key = generateKey();
        } while (shortToLong.count(key)); // Make sure key is unique
        shortToLong[key] = longUrl;
        return base + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl){
        string key = shortUrl.substr(base.size());
        return shortToLong[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));