#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); ++i) {
            tasks[i].push_back(i);
        }

        // Sort tasks by enqueue time
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;

        vector<int> res;
        long long time = tasks[0][0]; // current CPU time
        int i = 0; // task index

        while (i < tasks.size() || !minHeap.empty()) {
            while (i < tasks.size() && tasks[i][0] <= time) {
                minHeap.push({tasks[i][1], tasks[i][2]}); // {processingTime, index}
                ++i;
            }

            if (minHeap.empty()) {
                time = tasks[i][0];
            } else {
                auto [procTime, index] = minHeap.top();
                minHeap.pop();
                time += procTime;
                res.push_back(index);
            }
        }

        return res;
    }
};
