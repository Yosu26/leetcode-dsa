#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Count frequencies using hash map
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        // Custom comparator for priority queue
        auto comp = [](pair<string,int>& a, pair<string,int>& b) {
            return a.second > b.second || 
                   (a.second == b.second && a.first < b.first);
        };

        // Min heap to maintain k most frequent words
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(comp)> pq(comp);

        // Process each word
        for (const auto& [word, count] : freq) {
            pq.push({word, count});
            if (pq.size() > k) pq.pop();
        }

        // Build result array
        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        // Reverse to get descending frequency order
        reverse(result.begin(), result.end());
        return result;
    }
};