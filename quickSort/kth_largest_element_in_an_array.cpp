#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }

private:
    int quickSelect(vector<int>& nums, int left, int right, int kSmallest) {
        if (left == right) return nums[left];

        int pivotIndex = partition(nums, left, right);

        if (pivotIndex == kSmallest) return nums[pivotIndex];
        else if (pivotIndex > kSmallest)
            return quickSelect(nums, left, pivotIndex - 1, kSmallest);
        else
            return quickSelect(nums, pivotIndex + 1, right, kSmallest);
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int storeIndex = left;

        for (int i = left; i < right; ++i) {
            if (nums[i] < pivot) {
                swap(nums[storeIndex], nums[i]);
                ++storeIndex;
            }
        }

        swap(nums[storeIndex], nums[right]);
        return storeIndex;
    }
};