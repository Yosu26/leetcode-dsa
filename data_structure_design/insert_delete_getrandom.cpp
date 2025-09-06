#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> idx; // val -> index in nums
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (idx.count(val)) return false;
        nums.push_back(val);
        idx[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!idx.count(val)) return false;
        int last = nums.back();
        int i = idx[val];
        nums[i] = last;
        idx[last] = i;
        nums.pop_back();
        idx.erase(val);
        return true;
    }

    int getRandom() {
        int r = rand() % nums.size();
        return nums[r];
    }
};