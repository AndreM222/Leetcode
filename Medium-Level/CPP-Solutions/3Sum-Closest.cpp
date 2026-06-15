// --------------------------------------------[ Using Loops and Three Points ]--------------------------------------------
// O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int total = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums.size(); i++) {
            int left = i + 1, right = nums.size() - 1;
            int sum = 0;

            while(left < right) {
                sum = nums[i] + nums[left] + nums[right];

                if (sum == target) return target;

                if (abs(target - sum) < abs(target - total))
                    total = sum;

                if(sum < target) left++;
                else right--;
            }
        }

        return total;
    }
};
