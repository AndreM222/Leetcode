// --------------------------------------------[ Using Recursion ]--------------------------------------------
// O(N)
class Solution {
    void parser(vector<int>& nums, vector<int>& range, int target, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        if (range[0] <= -1 && nums[mid] <= target) parser(nums, range, target, left + 1, mid);

        if (target == nums[left]) range[0] = range[0] > -1 ? min(left, range[0]) : left;

        if (range[1] <= -1 && nums[mid + 1] >= target) parser(nums, range, target, mid + 1, right - 1);

        if(target == nums[right]) range[1] = max(right, range[1]);

    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range = {-1, -1};

        parser(nums, range, target, 0, nums.size() - 1);

        return range;
    }
};

// --------------------------------------------[ 2 Binary Search ]--------------------------------------------
// O(Log(N))
class Solution {
private:
    int parser(vector<int>& nums, int target, bool beginning) {
        int left = 0, right = nums.size() - 1, index = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                index = mid;
                if (beginning) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range = {-1, -1};

        range[0] = parser(nums, target, true);
        range[1] = parser(nums, target, false);

        return range;
    }
};
